#include <stdio.h>


void sum(int a,int b){
	printf("sum of - %d\n", a+b);
}


void decorator( void sum(int,int) ){
	sum(1,2);
}

int main(int argv,char* args[]){
	decorator(sum);
	return 0;	
};
