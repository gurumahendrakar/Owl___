
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <errno.h>
#include <string.h>



int main(){
        int pipe1[2],pipe2[2];

        if ( pipe(pipe1) == -1 ) {  return 1; }
        if ( pipe(pipe2) == -1 ) { return 2;  }

        int pid = fork();

        if ( pid == 0 ){
                 close(pipe1[1]);
                 close(pipe2[0]);
                 int x;
                 if ( read(pipe1[0],&x,sizeof(int)) == -1 ){
                        printf("something_issue in reading child process\n");
         };

                 int xx = 5000;
                 if ( write(pipe2[1],&xx,sizeof(int)) == -1 ){
                        printf("something issue in writeng in child process %s\n",strerror(errno));
                 }

                 close(pipe1[0]);
                 close(pipe2[1]);

                 printf(" parent get_ : -> %d \n",x);


        }else{

                close(pipe1[0]);
                close(pipe2[1]);

                int y = 1000;
                if ( write(pipe1[1],&y,sizeof(int)) == -1 ){
                        printf("something issue in writing parent  process\n");
                }

                int yy;
                if ( read(pipe2[0],&yy,sizeof(int)) == -1 ){
                        printf("something issue in reading parent process\n");
                }

                close(pipe1[1]);
                close(pipe2[0]);

                printf(" get child : -> %d \n",yy);
        }
};
