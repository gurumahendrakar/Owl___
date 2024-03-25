#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/wait.h>
#include <unistd.h>



//  pthread_cond_signal - (take one of thread  (threads cond waiting table)  )
// pthread_cond_wait() -> (unlocks mutex and wait for signal)
// pthread_cond_broadcast() -> send every thread s
// pthread_exit((void*) $return_value)


pthread_mutex_t mutex;
pthread_cond_t condfuel;

int fuel = 0;

void* Fuel(){
   while(1){
        pthread_mutex_lock(&mutex);
        fuel+=10;
        printf("filling fuel :::  %d\n\n",fuel);
        pthread_mutex_unlock(&mutex);
        pthread_cond_broadcast(&condfuel);
        sleep(1);
    }
}

void* Ride(){
    pthread_mutex_lock(&mutex);
    while( fuel < 30) {
        printf("not_getting fuel\n\n");
        pthread_cond_wait(&condfuel,&mutex);
    }
    fuel-=30;
    printf("decreasing fuel :::  %d\n\n",fuel);
    pthread_mutex_unlock(&mutex);
}


int main( int argc , char* argv){
    pthread_t threads[5];
    pthread_mutex_init(&mutex,NULL);
    pthread_cond_init(&condfuel,NULL);
    for (int i = 0 ; i < 5 ; i++){
        if ( i == 4){
            pthread_create(&threads[i],NULL,Fuel,NULL);
        }else{
            pthread_create(&threads[i],NULL,Ride,NULL);
        }
    }
    for (int i = 0 ; i < 5 ; i++){
        pthread_join(threads[i],NULL);
    }   
    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&condfuel);
}