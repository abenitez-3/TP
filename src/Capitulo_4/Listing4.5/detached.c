#include <unistd.h>
#include <stdio.h>
#include  <pthread.h>  
void*  thread_function  (void*  thread_arg)  
{ 
   /* Do  work  here...  */  
    printf("Hilo ejecutándose...\n");
    sleep(2);
    printf("Hilo finalizó.\n");
    return NULL;
}  
int  main  ()  
{ 
   pthread_attr_t attr;  
   pthread_t  thread;  
   pthread_attr_init  (&attr);  
   pthread_attr_setdetachstate  (&attr,  PTHREAD_CREATE_DETACHED);  
   pthread_create  (&thread,  &attr,  &thread_function,  NULL);  
   pthread_attr_destroy  (&attr);  
   /* Do  work  here...  */  
   printf("Hilo creado. El main sigue sin esperar al hilo.\n");
   sleep(3); // darle tiempo al hilo para terminar
   printf("Main termina.\n");
   /* No  need  to  join  the  second  thread.  */  
   return 0;  
} 