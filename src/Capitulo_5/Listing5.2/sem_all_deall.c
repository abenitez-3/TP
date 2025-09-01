#include <sys/ipc.h>  
#include <sys/sem.h>  
#include <sys/types.h>
#include <stdio.h>  
#include <stdlib.h>
#include <unistd.h>

/* We must define union semun ourselves. */  
union semun { 
    int val;  
    struct semid_ds *buf;  
    unsigned short int *array;  
    struct seminfo *__buf;  
};  

/* Obtain a binary semaphore's ID, allocating if necessary. */  
int binary_semaphore_allocation (key_t key, int sem_flags)  
{ 
    return semget (key, 1, sem_flags);  
}  

/* Deallocate a binary semaphore. All users must have finished their  
   use. Returns -1 on failure. */  
int binary_semaphore_deallocate (int semid)  
{ 
    union semun ignored_argument;  
    return semctl (semid, 1, IPC_RMID, ignored_argument);  
}

int main() {
    key_t key = 1234;  // clave fija para el semáforo
    int semid;

    // Crear semáforo
    semid = binary_semaphore_allocation(key, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("Error creando/obteniendo semáforo");
        exit(1);
    }
    printf("Semáforo creado con ID: %d\n", semid);

    // Esperar un poco para que puedas verificar con 'ipcs -s'
    printf("Semáforo activo. Ejecuta 'ipcs -s' en otra terminal para verlo.\n");
    sleep(25);

    // Eliminar semáforo
    if (binary_semaphore_deallocate(semid) == -1) {
        perror("Error eliminando semáforo");
        exit(1);
    }
    printf("Semáforo eliminado correctamente.\n");

    return 0;
}