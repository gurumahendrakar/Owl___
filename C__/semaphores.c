#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>

#define THREAD_NUM 6

int buffer[50];
int count = 0;

pthread_mutex_t mutex;
sem_t Full;
sem_t Empty;

void* producer(){
    while (1){
        int semValue;
        sem_getvalue(&Full,&semValue);
        printf("semphore_value %d\n",semValue);
        sem_wait(&Full);
        pthread_mutex_lock(&mutex);
        count++;
        printf(" producer count - %d\n",count);
        pthread_mutex_unlock(&mutex);
        sem_post(&Empty);
        if ( count > 50 ){
            break;
        }

    }
}

void* consumer(){
    printf("consumers --");
    while (1){
        sem_wait(&Empty);
        pthread_mutex_lock(&mutex);
        count--;
        printf(" consumer count - %d\n",count);
        pthread_mutex_unlock(&mutex);
        sem_post(&Full);

    }
}


int main( int argc , char* argv){
    pthread_t threads[THREAD_NUM];
    sem_init(&Full,0,sizeof(buffer)/4);    
    for (int i = 0 ; i < THREAD_NUM; i++){
        if (i < 3){
            pthread_create(&threads[i],NULL,&producer,NULL);
        }else{
             pthread_create(&threads[i],NULL,&consumer,NULL);    
        }
    }

    for (int i = 0 ; i < THREAD_NUM; i++){
        pthread_join(threads[i],NULL);
    }  

    sem_destroy(&Full);
};