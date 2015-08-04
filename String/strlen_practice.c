#include<stdio.h>

size_t My_strlen(char *str){
	
	int n = 0;
		while(*str != '\0'){
			n++;
			str++;
		}		
		return(n);
	}

int main(){

	char *s = "Hi!!My name is Sunny.";
	printf("size of s = %d \n",My_strlen(s));
		
	return(0);
}
