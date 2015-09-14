#include<stdio.h>

void showbinary_bits(unsigned int x){
	int i;
	for(i=sizeof(int)*8-1 ; i>=0 ;i--){
		(x&(1<<i))?(putchar('1')):(putchar('0'));
	}
	printf("\n");

}

int main(){

	unsigned int number = 5225;

	printf("number in Decimal is %d ,number in Binary is - ",number);
	showbinary_bits(number); 
	

}
