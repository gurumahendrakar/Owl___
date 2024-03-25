#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>



int main(int argc,char* argv[]){

int fd1;
	if (mkfifo("/tmp/myfifo",0666) == -1 ){
		if ( errno != EEXIST ){
			printf("%s",strerror(errno));
			return 1;
		} 
	}

	int fd = open("/tmp/myfifo",O_WRONLY);
	int buffer[] = {1000,1000,1000,1000,1000};
	if ( write(fd,&buffer,sizeof(buffer)) == -1 ){
		printf("%s\n",strerror(errno));
	}
    return 0;	
}
