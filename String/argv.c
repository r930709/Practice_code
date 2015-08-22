#include<stdio.h>
#include<stdlib.h>

int main(void){
    
    char * buff[] = {"hijklpjkjvkjfkvjfkvjk","hello","yowwwwwwwwwww"};
    char buff2[5] = "hello";
    printf("sizeof(buff2) = %d\n",sizeof(buff2));   
    printf("sizeof(buff[]) = %d | sizeof(buff[0]) = %d | sizeof(buff[1]) = %d |sizeof(buff[2]) = %d \n",sizeof(buff),sizeof(buff[0]),sizeof(buff[1]),sizeof(buff[2]));
    
    printf("%s | %s\n",buff[0],buff[1]);
    printf(" *(buff[0]+0) = %c *(buff[0]+1) = %c *(buff[0]+2) = %c *(buff[0]+3) = %c\n",*(buff[0]+0),*(buff[0]+1),*(buff[0]+2),*(buff[0]+3));
    printf(" *(buff[1]+0) = %c *(buff[1]+1) = %c *(buff[1]+2) = %c *(buff[1]+3) = %c *(buff[1]+4) = %c\n",*(buff[1]+0),*(buff[1]+1),*(buff[1]+2),*(buff[1]+3),*(buff[1]+4));
    printf(" *(buff[2]+0) = %c *(buff[2]+1) = %c *(buff[2]+2) = %c \n",*(buff[2]+0),*(buff[2]+1),*(buff[2]+2));
    
    
    printf("buff[0] address = %p | buff[1] address = %p \n",buff[0],buff[1]);
    printf("*(buff[0]+0) = %p | *(buff[0]+1) = %p \n",(buff[0]+0),(buff[0]+1));
    printf("*(buff[1]+0) = %p | *(buff[1]+1) = %p | *(buff[1]+2) = %p | *(buff[1]+3) = %p | *(buff[1]+4) = %p\n",(buff[1]+0),(buff[1]+1),(buff[1]+2),(buff[1]+3),(buff[1]+4));
    printf("*(buff[2]+0) = %p *(buff[2]+1) = %p\n",(buff[2]+0),(buff[2]+1));
    
           return(0);
    }
