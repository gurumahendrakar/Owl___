#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argv,char* args[]){
    int fd[2];

    if ( pipe(fd) == -1 ){ return 1;};
	

    int pid = fork();
	if ( pid == -1 ){ return 2;};
	
    if ( pid == 0 ){
		int buffer[5];		
		if ( read(fd[0],&buffer,sizeof(buffer)) == -1 ){
			printf("error_reading from  child\n");
			return 4;
		};

		int y = 1000;
		if ( write(fd[1],&y,sizeof(int)) == -1 ) { 
			printf("error_writing from child\n");
			return 5; 
		};

		close(fd[0]);
		close(fd[1]);		

		for ( short int i = 0; i < sizeof(buffer)/4; i++ ){
			printf("%d ",buffer[i]);
		};
		printf("\n");

					
	}else{
		int buffer[5] = {1,2,3,4,5};
		int err_ = write(fd[1],&buffer,sizeof(buffer));
		if (err_ == -1) {
			printf("Something Issue In Parent Writing\n");
			return 3; 
		};
		
		close(fd[1]);

		int y;
		err_ = write(fd[0],&buffer,sizeof(int));
		if ( err_ == -1 ){
			printf("something Issue In Parent Reading\n");
		};		
		close(fd[0]);
		printf("Y  : %d\n",y);
		wait(NULL);
	};
}
