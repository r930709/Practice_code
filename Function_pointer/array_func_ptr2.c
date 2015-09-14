#include<stdio.h>

typedef int (*Customoperation)(int);

int power(int v){
	return(v*v);
}

void custom_for_each(int *temp_array,unsigned int size,Customoperation op){
	
	unsigned int i;
	for(i=0;i<size;i++){
		*(temp_array+i) = op(i);
	}
}


int main(){
	int size = 10;
	int pArray[size];
	unsigned int i;	

	for(i = 0;i< size;i++){
		pArray[i] = i;
	}
	
	custom_for_each( pArray,size, &power);

	for(i=0;i<size;i++){
		printf("%d\n",pArray[i]);
	}
	return(0);	
}

