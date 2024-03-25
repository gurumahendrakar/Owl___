#include <stdio.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>



int main(int argc,char* argv[]){

int fd1;
	
	int buffer[5];
	int fd = open("/tmp/myfifo",O_RDONLY);
	if (fd == -1){
		printf("file_open problem");
		return 2;
	};
	
	int err_ = read(fd,&buffer,sizeof(buffer));
	if ( err_ == -1 ){
		printf("read_problem");
		return 3;
	}	
	
	int sum = 0;
	for (short int i = 0 ; i < sizeof(buffer)/4  ; i++ ){
		if ( read(fd,&buffer[i],sizeof(int))  == -1 ){
			printf("something_issue in reading");
		}
		
		sum+=buffer[i];	
	};

	printf("sum of -> %d",sum);

	
    return 0;	
}
