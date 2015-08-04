#include<stdio.h>

char* My_strcat(char *destination,const char *source){

	size_t i,j;
		
		for(i=0;*(destination+i) != '\0';i++);
		
		for(j=0;*(source+j) != '\0';j++){
			
			*(destination+i+j) = *(source+j);
		}
		*(destination+i+j) = '\0';	
		return(destination);
	}

int main(){

	char s[] = "Hi!!My name is Sunny.";
	char d[] = "welecome !! Hello world!!";
	

	printf("%s\n",My_strcat(d,s));
		
	return(0);
}
