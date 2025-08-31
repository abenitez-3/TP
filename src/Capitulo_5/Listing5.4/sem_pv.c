#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/* Wait on a binary semaphore. Block until the semaphore value is positive,
then decrement it by 1. */
int binary_semaphore_wait(int semid) {
    struct sembuf operations[1];
    operations[0].sem_num = 0;
    operations[0].sem_op = -1;   // Decrementar
    operations[0].sem_flg = SEM_UNDO;
    return semop(semid, operations, 1);
}

/* Post to a binary semaphore: increment its value by 1.
   This returns immediately. */
int binary_semaphore_post(int semid) {
    struct sembuf operations[1];
    operations[0].sem_num = 0;
    operations[0].sem_op = 1;    // Incrementar
    operations[0].sem_flg = SEM_UNDO;
    return semop(semid, operations, 1);
}

int main() {
    key_t key = 1234;   // clave del semáforo
    int semid;
    union semun {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
        struct seminfo *__buf;
    } arg;

    // Crear conjunto de 1 semáforo
    semid = semget(key, 1, IPC_CREAT | 0666);
    if (semid == -1) {
        perror("Error creando semáforo");
        exit(1);
    }

    // Inicializar semáforo en 1 (disponible)
    arg.val = 1;
    if (semctl(semid, 0, SETVAL, arg) == -1) {
        perror("Error inicializando semáforo");
        exit(1);
    }

    printf("Semáforo creado con ID %d\n", semid);

    printf("Esperando semáforo (wait)...\n");
    binary_semaphore_wait(semid);
    printf("Dentro de la sección crítica \n");
    sleep(3); // simulamos trabajo
    printf("Saliendo de la sección crítica...\n");

    binary_semaphore_post(semid);
    printf("Se liberó el semáforo \n");

    // Eliminar semáforo
    if (semctl(semid, 0, IPC_RMID, arg) == -1) {
        perror("Error eliminando semáforo");
        exit(1);
    }
    printf("Semáforo eliminado correctamente\n");

    return 0;
}
