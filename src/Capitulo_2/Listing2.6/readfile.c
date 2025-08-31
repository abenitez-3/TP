#include <fcntl.h>  
#include <stdlib.h>  
#include <sys/stat.h>  
#include <sys/types.h>  
#include <unistd.h>
#include <sys/stat.h>//agregado para saber la longitud del archivo
#include <stdio.h>//agregado para saber la longitud del archivo

char* read_from_file (const char* filename, size_t length)  
{ 
  char* buffer;  
  int fd;  
  ssize_t bytes_read;  
  
  /* Allocate the buffer.  */  
  buffer = (char*) malloc (length);  
  if (buffer == NULL)  
    return NULL;  
  
    /* Open the file.  */  
  fd = open (filename, O_RDONLY);  
  if (fd == -1) { 
    /* open failed. Deallocate buffer before returning.  */  
    free (buffer);  
    return NULL;  
  }  
  
  /* Read the data.  */  
  bytes_read = read (fd, buffer, length);  
  if (bytes_read != length) { 
    /* read failed. Deallocate buffer and close fd before returning.  */  
    free (buffer);  
    close (fd);  
    return NULL;  
  }  
  
  /* Everything's fine. Close the file and return the buffer.  */  
  close (fd);
  return buffer;
}

int main(int argc, char const *argv[]){
  struct stat st;//agregado para saber la longitud del archivo
  stat(argv[1], &st);//agregado para saber la longitud del archivo
  size_t length = st.st_size;//agregado para saber la longitud del archivo
  if (argc == 2){
    printf("%s", read_from_file(argv[1], length));
  }else{
    printf("Se debe proporcionar un unico argumento y debe ser el nombre de un archivo\n");
  }
  return 0;
}