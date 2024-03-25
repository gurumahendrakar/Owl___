#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]){
	int array[]  = {5,5,5,5,10,10,10,10};
	int start,end;
	int sum  = 0;
	int fd[2];
	
	if ( pipe(fd) == -1){
		return 1;
	}
	int pid  = fork();
	
	if ( pid == 0 ){
		start = 0;
		end   = (sizeof(array)/4)/2;
	}else{
		start = (sizeof(array)/4)/2;
		end = (sizeof(array)/4);
	}
	
	for ( short int i = start; i < end; i++ ){
		sum+= array[i];
	}

	if ( pid == 0){
		close(fd[0]);
		write(fd[1],&sum,sizeof(int));
		close(fd[1]);
		printf("child_fd %p\n",fd);
	}else{	
		wait(NULL);
		int childSum;
		close(fd[1]);
	 	read(fd[0],&childSum,sizeof(int));
		close(fd[0]);
		sum+=childSum;
		printf("parent_fd %p\n",fd);
		printf("Sum Of : %d \n",sum);
	}
	
	
	
}
