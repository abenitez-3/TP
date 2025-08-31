#include <pthread.h>  
#include <stdio.h>
#include <stdlib.h>  
#include <unistd.h>

void* thread_function (void* arg) { 
  fprintf (stderr, "child thread pid is %d\n", (int) getpid ());  
  /* Spin forever.  */  
  while (1);  
  return NULL;
}  
int main () { 
  pthread_t thread;  

  fprintf (stderr,"Apriete ctrl+z para cerrar (la app queda en loop)\n");
  fprintf (stderr, "main thread pid is %d\n", (int) getpid ());  
  pthread_create (&thread, NULL, &thread_function, NULL);  
  /* Spin forever.  */  
  while (1);  
  return 0;  
}
/*Por una actualizacion de linux en la forma que se usa el getpid con los hilos
El pid padre y el pid hijo seran el mismo*/