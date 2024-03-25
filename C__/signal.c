#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <signal.h>

void SignStop(int sig){
	printf("SignStop Handleing\n");
	fflush(stdout);
};
	
int main(int argc, char *argv[]){
	struct sigaction sa;
	sa.sa_handler = &SignStop;
	sa.sa_flags = SA_RESTART;
	sigaction(SIGCONT,&sa,NULL);
	int x;
	printf("input a number : ");
	scanf("%d",&x);
	return 0;	
};
