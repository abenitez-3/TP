#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
#include <sys/socket.h>  
#include <sys/un.h>  
#include <unistd.h>  

/* Read text from the socket and print it out. Continue until the  
   socket closes. Return nonzero if the client sent a "quit"  
   message, zero otherwise.  */  
int server (int client_socket) { 
    while (1) { 
        int length;  
        char* text;  
        
        /* First, read the length of the text message from the socket. If  
        read returns zero, the client closed the connection.  */  
        if (read (client_socket, &length, sizeof (length)) == 0)
            return 0;  
        
        /* Allocate a buffer to hold the text.  */  
        text = (char*) malloc (length + 1);  
        if (!text) {
            perror("malloc");
            return 1;
        }

        /* Read the text itself, and print it.  */  
        int bytes_read = read (client_socket, text, length);
        if(bytes_read <= 0){
            free(text);
            return 0;
        }
        
        text[bytes_read] = '\0';
        
        printf ("%s\n", text);  
        
        // chequear quit ANTES de liberar
        int quit = !strcmp(text, "quit");

        /* Free the buffer.  */  
        free (text);  
        
        return quit;  
    }  
}

int main (int argc, char* const argv[]) { 
    const char* const socket_name = argv[1];  
    int socket_fd;  
    struct sockaddr_un name;  
    int client_sent_quit_message;  
    
    /* Create the socket.   */  
    socket_fd = socket (PF_LOCAL, SOCK_STREAM, 0);  
    
    /* Indicate that this is a server.   */  
    name.sun_family = AF_LOCAL;  
    strcpy (name.sun_path, socket_name);  
    
    /* Borrar si ya existe */
    unlink(socket_name);

    /* Bind con cast correcto */
    if (bind (socket_fd, (struct sockaddr*)&name, sizeof(name)) == -1){
        perror("bind");
        exit(1);
    }
    
    /* Listen for connections.   */  
    listen (socket_fd, 5);  
    
    /* Repeatedly accept connections, spinning off one server() to deal  
        with  each  client.  Continue  until  a  client  sends  a  "quit"  
        message.   */  
    do { 
        struct sockaddr_un client_name;  
        socklen_t client_name_len;  
        int client_socket_fd;  
        
        /* Accept a connection.   */  
        client_socket_fd = accept (socket_fd, (struct sockaddr*) &client_name, &client_name_len);  
        
        /* Handle the connection.   */  
        client_sent_quit_message = server (client_socket_fd);  
        
        /* Close our end of the connection.   */  
        close (client_socket_fd);  
    } while (!client_sent_quit_message);  
    
    /* Remove the socket file.   */  
    close (socket_fd);  
    unlink (socket_name);  
    return 0;  
}