#include  <pthread.h>
#include  <iostream>
#include  <unistd.h>

bool value = false;

extern void change_bool_value(){
    value = !value;
}

extern bool should_exit_thread_immediately (){
    return value;
};

class  ThreadExitException{ 
    public:  
        
        /* Create  an  exception-signaling  thread  exit  with  RETURN_VALUE.  */  
        ThreadExitException (void*  return_value)  
            : thread_return_value_  (return_value){}  
        
        /*  Actually  exit  the  thread,  using  the  return  value  provided  in  the  
        constructor.  */  
        void*  DoThreadExit  ()  { 
            pthread_exit  (thread_return_value_);
            return nullptr; // nunca se ejecuta, pero evita warnings  
        }  
    private:  
        /*  The  return  value  that  will  be  used  when  exiting  the  thread.   
        */
        void*  thread_return_value_;  
};

// Simula un trabajo dentro del hilo
void  do_some_work  ()  { 
    while  (1)  { 
        /*  Do  some  useful  things  here...  */
        printf("holaa\n");
        sleep(1);

        if  (should_exit_thread_immediately  ())  
            throw  ThreadExitException  (/*  thread's  return  value  =  */ NULL);  
    }  
}

// Función que ejecuta el hilo
void*  thread_function  (void*)  { 
    try  { 
        do_some_work  ();  
    }  
    catch  (ThreadExitException  ex)  { 
        /*   Some  function  indicated  that  we  should  exit  the  thread.  */
        printf("El hilo recibió señal de salida, cerrando...\n");
        ex.DoThreadExit  ();
    }
    return NULL;
}

void* thread_sleep_function(void * arg){
    sleep(3);
    change_bool_value();
    printf("\ncambia el valor de estado a true despues de 3 segundos\n");
    return NULL;
}

int main(){
    pthread_t thread;
    pthread_t time;

    pthread_create(&thread, NULL, &thread_function, NULL);
    pthread_create(&time, NULL, &thread_sleep_function, NULL);

    // esperar ambos hilos
    pthread_join(thread, NULL);
    pthread_join(time, NULL);
    
    return 0;
}