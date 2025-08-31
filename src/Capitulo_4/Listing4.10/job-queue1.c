#include  <malloc.h>  
#include <pthread.h>
#include <stdio.h>
struct job  { 
   /* Link field for linked list.  */  
   struct job*  next;  
   /* Other fields describing work to be done...  */  
};  
/* A linked list of pending  jobs.  */  
struct job* job_queue;  
/* Process queued jobs until the queue is empty.  */ 
void process_job(struct job* job) {
    printf("Procesando un trabajo en thread_function...\n");
} 
void*  thread_function (void*  arg)  
{ 
   while (job_queue  !=  NULL)  { 
      /* Get the next available job.  */  
      struct  job*  next_job  =  job_queue;  
      /* Remove this  job from  the  list.  */  
      job_queue  =  job_queue->next;  
      /* Carry out the work.  */  
      process_job (next_job);  
      /* Clean  up.  */  
      free (next_job);  
   }  
   return  NULL;  
}  
int main() {
    pthread_t thread;

    // Initialize the job_queue with some dummy data
    struct job* job1 = malloc(sizeof(struct job));
    struct job* job2 = malloc(sizeof(struct job));
    job1->next = job2;
    job2->next = NULL;
    job_queue = job1;

    pthread_create(&thread, NULL, thread_function, NULL);
    pthread_join(thread, NULL);

    return 0;
}