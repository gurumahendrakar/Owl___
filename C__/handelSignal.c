#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <time.h>
#include <signal.h>

void SIGTSTP_H(){
	printf("SIGTSTP MOVE");
}
	
int main(int argc, char *argv[]){
	struct sigaction sig;
	sig.sa_handler = &SIGTSTP_H; // --> Use This Every Unix Version Supports;
	sig.sa_flags = SA_RESTART;

	//signal(SIGTSTP,&SIGTSTP_H); --> Every Unix Verions not Support ;

	int x;
	printf("Input Number -> ");
	scanf("%d",&x);

};	
