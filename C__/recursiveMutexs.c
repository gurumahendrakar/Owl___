#include <unistd.h>
#include <pthread.h>
#include <stdio.h>


#define THREAD_NUM 4



pthread_mutex_t mutex;
void* run(){
    pthread_mutex_lock(&mutex);
    pthread_mutex_lock(&mutex);
    printf("everything_fine\n");
    pthread_mutex_unlock(&mutex);
    pthread_mutex_unlock(&mutex);
}

int main(){
    pthread_t th[THREAD_NUM];
    pthread_mutexattr_t RecursiveMutexAttribute;
    pthread_mutexattr_init(&RecursiveMutexAttribute);
    pthread_mutexattr_settype(&RecursiveMutexAttribute,PTHREAD_MUTEX_RECURSIVE);
    pthread_mutex_init(&mutex,&RecursiveMutexAttribute);

    int i;
    for (i = 0;i <4; i++){
        if ( pthread_create(&th[i],NULL,&run,NULL) == -1){
            printf("error_thread * (creation) \n");
        }
    }

    for (i = 0;i <4; i++){
        pthread_join(th[i],NULL);
    };    

}