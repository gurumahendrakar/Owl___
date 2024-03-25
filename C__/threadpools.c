#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>
#include <stdlib.h>


#define MAX_TASKS 20

pthread_mutex_t mutex;
pthread_cond_t  cond;


typedef struct Task{
    int a;
    int b;
} task;


task TaskQueue[MAX_TASKS];
int taskCount = 0;


void executeTask(task* Task){
    int result  = Task->a + Task->b;
    printf("sum of result : %d\n",result);
}


void* startThread(void* args){
    while(1){
        printf("something_");
        while (taskCount == 0){
            pthread_cond_wait(&cond,&mutex);
        }
            pthread_mutex_lock(&mutex);
            task tk;
            tk = TaskQueue[taskCount];
            executeTask(&tk);
            taskCount--;
            pthread_mutex_unlock(&mutex);
    }
}


void* AddTask(){
    while (1){
        if ( taskCount < MAX_TASKS ){
            pthread_mutex_lock(&mutex);
            task tk;
            tk.a = rand() % 100;
            tk.b = rand() % 100;
            TaskQueue[taskCount] = tk;
            taskCount++;
            pthread_mutex_unlock(&mutex);
            pthread_cond_signal(&cond);
        }
    }
}    
int main(int argc,char* argv){
    srand(time(NULL));
    task tk = {
        .a = 5,
        .b = 15
    };

    pthread_t threads[2];
    pthread_cond_init(&cond,NULL);
    pthread_mutex_init(&mutex,NULL);
    pthread_mutex_destroy(&mutex);

    for (short int i = 0 ; i < 2 ; i++){
        if ( i % 2 == 0){
            pthread_create(&threads[i],NULL,&startThread,NULL);
        }else{
            //pthread_create(&threads[i],NULL,&AddTask,NULL);
        }
    }
    pthread_join(threads[0],NULL);


    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    return 0;
}