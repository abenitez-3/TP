#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int thread_flag;  
pthread_cond_t thread_flag_cv;  
pthread_mutex_t thread_flag_mutex;  

// Simulación de trabajo
void do_work() {
    printf("Hilo trabajando...\n");
    sleep(1); // simula trabajo que toma tiempo
}

void initialize_flag ()  
{ 
   /* Initialize the mutex and condition variable.  */  
   pthread_mutex_init (&thread_flag_mutex, NULL);  
   pthread_cond_init (&thread_flag_cv, NULL);  
   /* Initialize  the  flag  value.  */  
   thread_flag = 0;  
}  

/* Calls do_work repeatedly while the thread flag is set; blocks if  
   the flag is clear.  */  

void* thread_function (void* thread_arg)  
{ 
   /* Loop infinitely.  */  
   while (1) { 
       /* Lock the mutex before accessing the flag value.  */  
       pthread_mutex_lock (&thread_flag_mutex);  
       while (!thread_flag)  
            /* The flag is clear. Wait for a signal on the condition  
               variable, indicating that the flag value has changed. When the  
               signal arrives and this thread unblocks, loop and check the  
               flag again.  */  
            pthread_cond_wait (&thread_flag_cv, &thread_flag_mutex);  
       /* When we've gotten here, we know the flag must be set. Unlock  
           the mutex.  */  
       pthread_mutex_unlock (&thread_flag_mutex);  
       /* Do some work.  */  
       do_work ();  
   }  
   return NULL;  
}  

/* Sets the value of the thread flag to FLAG_VALUE.  */
  
void set_thread_flag (int flag_value)  
{ 
   /* Lock the mutex before accessing the flag value.  */  
   pthread_mutex_lock (&thread_flag_mutex);  
   /* Set the flag value, and then signal in case thread_function is  
      blocked, waiting for the flag to become set. However,  
      thread_function can't actually check the flag until the mutex is  
      unlocked.  */  
    thread_flag  =  flag_value;  
    pthread_cond_signal  (&thread_flag_cv);  
    /*  Unlock  the  mutex.   */  
    pthread_mutex_unlock  (&thread_flag_mutex);  
}

int main() {
    pthread_t worker;

    // inicializar recursos
    initialize_flag();

    // crear hilo
    pthread_create(&worker, NULL, thread_function, NULL);

    printf("Activando bandera por 5 segundos...\n");
    set_thread_flag(1);  // activar
    sleep(5);

    printf("Desactivando bandera (el hilo se queda bloqueado)...\n");
    set_thread_flag(0);  // desactivar
    sleep(3);

    printf("Activando nuevamente bandera por 3 segundos...\n");
    set_thread_flag(1);
    sleep(3);

    printf("Fin del programa (el hilo sigue en bucle infinito)\n");
    return 0;
}