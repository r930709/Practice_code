#include<stdio.h>
#include<stdlib.h>

size_t strlen(char *str){
 
         int n = 0;
                 while(*str != '\0'){
                         n++;
                         str++;
                 }
                 return(n);
         
} 

char* My_strncat(char *destination,const char *source,size_t size){

	size_t dest_len = strlen(destination);
	size_t i;
		
		for(i=0; *(source+i) != '\0' && (i < size);i++){
			*(destination+dest_len+i) = *(source+i);  
		}
		*(destination+dest_len+i) = '\0';	
		
		return(destination);
	}

int main(){

	char *s = "Hi!!My name is Sunny.";
	char *d = "welecome !! Hello world!!";
	char *buffer = malloc(strlen(s)+strlen(d)+1);
	//printf("%s\n",My_strlcat(d,s,));
	
	My_strncat(buffer,d,strlen(d));
	My_strncat(buffer,s,strlen(s));
//	My_strncat(buffer,d,5);
//	My_strncat(buffer,s,10);
	printf("%s\n",buffer);
			
	return(0);
}
