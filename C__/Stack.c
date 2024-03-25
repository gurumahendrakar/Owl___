#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int stack[2];
int inc  = 0;



void push(int x){
    if( inc > 1){
        fprintf(stderr,"Stack Have No Space <SG>\n");
        return ;
    };

    stack[inc] = x;
    inc++;
}

int pop(){
   if (inc  ==  0){
        fprintf(stderr,"Stack Have No Space <SG>\n");
        return 0 ;
   }
   int pop_ = stack[inc];
   inc--;

}


int main(int argc, char* argv[]){
    push(1);
    push(2);
    pop();
    push(3);
    printf("%d - %d\n",stack[0],stack[1]);
    return 0;
}