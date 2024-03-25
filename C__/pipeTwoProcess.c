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
		dup2(fd[1],1);
		close(fd[0]);
		close(fd[1]);	
		if ( execlp("ping","ping","-c","5","google.com",NULL) == -1 ){
			printf("something_issue ping");
			return 4;
		};
		printf("pid_1 completed\n");
		return 0;
	}

	int pid2 = fork();
	if (pid2 == -1){ return 3; };
	
	if (pid2 == 0){
		dup2(fd[0],0);
		close(fd[0]);
		close(fd[1]);
		execlp("grep","grep","-ie","rtt",NULL);
		return 0;
	};
	
	close(fd[0]);
	close(fd[1]);
	waitpid(pid,NULL,0);
	waitpid(pid2,NULL,0);
	printf("completed_fully\n");
	return 0;

}
