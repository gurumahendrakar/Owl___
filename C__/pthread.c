#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int mails = 0;
pthread_mutex_t  mutex;


void* routine(void* arg){
	if ( pthread_mutex_trylock(&mutex) == 0 ){
			mails+= *((int*)arg);
			sleep(1);
			pthread_mutex_unlock(&mutex);
	}else{
		printf("someone_there\n");
	}
};



int main(int argc,char* argv[]){
	pthread_t threads[8];
	int array[] = {8,2,3,4,5,6,7,8};

	pthread_mutex_init(&mutex,NULL);
	for (int i = 0 ; i <8 ; i++ ){
		pthread_create(&threads[i],NULL,&routine,((void*) &array[i]));
		
	}


	//for (int i = 0 ; i <8 ; i++ ){
	//	pthread_join(threads[i],NULL);
	//}
	
	pthread_mutex_destroy(&mutex);
	printf("total_ mails : %d\n",mails);

	
};	

