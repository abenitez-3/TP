#include <stdio.h>
#include <unistd.h>
#include <signal.h>  
#include <string.h>  
#include <sys/types.h>  
#include <sys/wait.h>  
#include <stdlib.h>
sig_atomic_t child_exit_status;  
void clean_up_child_process (int signal_number)  
{ 
  /* Clean up the child process.  */  
  int status;  
  wait (&status);  
  /* Store its exit status in a global variable.  */  
  child_exit_status = status;  
}  
int main ()  
{ 
  /* Handle SIGCHLD by calling clean_up_child_process.  */  
  struct sigaction sigchld_action;  
  memset (&sigchld_action, 0, sizeof (sigchld_action));  
  sigchld_action.sa_handler = &clean_up_child_process;  
  sigaction (SIGCHLD, &sigchld_action, NULL);  
  /* Now do things, including forking a child process.  */  
  pid_t pid = fork();
  if (pid == 0) {
        // Proceso hijo
        printf("Soy el hijo. PID: %d\n", getpid());
        sleep(2); // Simula trabajo
        exit(42); // Termina con código 42
    } else {
        // Proceso padre
        printf("Soy el padre. PID: %d. Esperando al hijo...\n", getpid());

        // Espera un poco para que el handler tenga tiempo de ejecutarse
        sleep(5);

        printf("El hijo terminó con estado: %d\n", WEXITSTATUS(child_exit_status));
    }
  /* ...  */  
 return 0;  
}  