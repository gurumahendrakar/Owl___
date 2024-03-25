#include <stdio.h>
#include <pthread.h>

pthread_barrier_t barrier;


void* routine(void* arg){
    printf("-------------------\n");
	pthread_barrier_wait(&barrier);
    pthread_barrier_wait(&barrier);
	printf("Hlo_From_Barrier\n");
};
    

int main(int argc,char* argv[]){
	pthread_t threads[8];

	pthread_barrier_init(&barrier,NULL,3);
	for (int i = 0 ; i <8 ; i++ ){
		pthread_create(&threads[i],NULL,&routine,NULL);
    };
	
	for (int i = 0 ; i <8 ; i++ ){
		pthread_join(threads[i],NULL);
	}
	pthread_barrier_destroy(&barrier);	
};	

