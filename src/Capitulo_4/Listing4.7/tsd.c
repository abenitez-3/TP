#include <malloc.h>  
#include <pthread.h>  
#include <stdio.h>  
/* The key used to associate a log file pointer with each thread.  */  
static pthread_key_t  thread_log_key;  
/* Write MESSAGE to the log file for the current thread.  */  
void write_to_thread_log (const char* message)  
{ 
   FILE* thread_log  =  (FILE*) pthread_getspecific (thread_log_key);  
   fprintf (thread_log,  "%s\n", message);  
}  
/* Close the log file pointer THREAD_LOG.  */  
void close_thread_log (void*  thread_log)  
{ 
   fclose ((FILE*) thread_log);  
}  
void* thread_function(void* args)  
{ 
    char thread_log_filename[100];  
    FILE* thread_log;  

    sprintf(thread_log_filename,"src/Capitulo_4/Listing4.7/thread%d.log", (int)pthread_self()); 

    printf("Intentando abrir archivo: %s\n", thread_log_filename);

    thread_log = fopen(thread_log_filename, "w");  
    if (!thread_log) {
        perror("Error abriendo el archivo de log");
        pthread_exit(NULL);
    }

    pthread_setspecific(thread_log_key, thread_log);  
    write_to_thread_log("Thread starting.");  

    return NULL;  
}
 
int main ()  
{ 
   int i;  
   pthread_t threads[5];  
   /* Create a key to associate thread log file pointers in  
      thread-specific data. Use close_thread_log to clean up the file  
      pointers.  */  
   pthread_key_create (&thread_log_key, close_thread_log);  
   /* Create threads to do the work.  */  
   for (i = 0; i < 5; ++i)  
      pthread_create (&(threads[i]), NULL, thread_function, NULL);  
   /* Wait for all threads to finish.  */  
   for (i = 0; i < 5; ++i)  
      pthread_join (threads[i], NULL);  
   return 0;  
}  