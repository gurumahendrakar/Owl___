#include <pthread.h>
#include <stdio.h>
#include <unistd.h>


#define THREAD_NUM 4

void* run(){
    printf("everything_fine\n");
}

int main(){
    pthread_t th[THREAD_NUM];
    pthread_attr_t detachThread;
    pthread_attr_init(&detachThread);
    pthread_attr_setdetachstate(&detachThread,PTHREAD_CREATE_DETACHED);
    int i;
    for (i = 0;i <4; i++){
        if ( pthread_create(&th[i],&detachThread,&run,NULL) == -1){
            printf("error_thread * (creation) \n");
        }
    }

    pthread_exit(0);   
}