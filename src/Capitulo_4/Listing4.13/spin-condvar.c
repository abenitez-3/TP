#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

int thread_flag;  
pthread_mutex_t thread_flag_mutex;  

void initialize_flag ()  
{ 
   pthread_mutex_init (&thread_flag_mutex, NULL);  
   thread_flag = 0;  
}  

// Simulación de trabajo
void do_work() {
    printf("Hilo trabajando...\n");
    sleep(1); // simula trabajo que toma tiempo
}

/* Calls do_work repeatedly while the thread flag is set; otherwise  
   spins.  */  

/* Hilo que revisa la bandera */
void* thread_function (void* thread_arg) { 
   while (1) { 
       int flag_is_set;
       
       /* Protect the flag with a mutex lock.  */  
       pthread_mutex_lock (&thread_flag_mutex);  
       flag_is_set = thread_flag;  
       pthread_mutex_unlock (&thread_flag_mutex);  
       
        if (flag_is_set)  
            do_work ();  
            /* Else don't do anything. Just loop again.  */
        else
            usleep(100000);// dormir 0.1s para no quemar CPU
    }  
    return NULL;  
}

/* Sets the value of the thread flag to FLAG_VALUE.  */  

void set_thread_flag (int flag_value)  
{ 
    /* Protect the flag with a mutex lock.  */  
    pthread_mutex_lock (&thread_flag_mutex);  
    thread_flag = flag_value;  
    pthread_mutex_unlock (&thread_flag_mutex);  
}

int main() {
    pthread_t worker;

    // inicializar y crear hilo
    initialize_flag();
    pthread_create(&worker, NULL, thread_function, NULL);

    printf("Activando bandera por 5 segundos...\n");
    set_thread_flag(1);  // activar
    sleep(5);

    printf("Desactivando bandera por 3 segundos...\n");
    set_thread_flag(0);  // desactivar
    sleep(3);

    printf("Activando nuevamente bandera por 2 segundos...\n");
    set_thread_flag(1);
    sleep(2);

    printf("Fin del programa. El hilo seguirá activo en bucle infinito.\n");
    
    return 0;
}