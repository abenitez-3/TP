#include <sys/types.h>  
#include <sys/ipc.h>  
#include <sys/sem.h>  
#include <stdio.h>
#include <stdlib.h>
/* We must define union semun ourselves. */  
union semun { 
    int val;  
    struct semid_ds *buf;  
    unsigned short int *array;  
    struct seminfo *__buf;  
};  
/* Initialize a binary semaphore with a value of 1. */  
int binary_semaphore_initialize (int semid)  
{ 
    union semun argument;  
    unsigned short values[1];  
    values[0] = 1;  
    argument.array = values;  
    return semctl (semid, 0, SETALL, argument);  
}
void binary_semaphore_wait(int semid) {
    struct sembuf operation = {0, -1, 0}; // restar 1
    semop(semid, &operation, 1);
}

void binary_semaphore_signal(int semid) {
    struct sembuf operation = {0, +1, 0}; // sumar 1
    semop(semid, &operation, 1);
}
int main() {
    key_t key = ftok("/tmp", 'A'); // Clave única para el semáforo
    if (key == -1) {
        perror("ftok");
        exit(EXIT_FAILURE);
    }

    int semid = semget(key, 1, IPC_CREAT | 0666); // Creamos 1 semáforo
    if (semid == -1) {
        perror("semget");
        exit(EXIT_FAILURE);
    }

    // Inicializar semáforo a 1
    if (binary_semaphore_initialize(semid) == -1) {
        perror("semctl - initialize");
        exit(EXIT_FAILURE);
    }

    printf("Semáforo creado e inicializado con ID: %d\n", semid);
    return 0;
}