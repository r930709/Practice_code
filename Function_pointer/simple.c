#include<stdio.h>

int myAdd(int a,int b){
	return(a+b);
}
int mySub(int a,int b){
	return(a-b);
}

typedef int (*MathFunc)(float,int);

int do_math(float a,int b){
	return(a*b);
}

void call_a_func(MathFunc call_this){

	int output = call_this(5.5,6);
	printf("%d\n",output);
}


int main(){
	
	int (*my_func_ptr)(int ,int );
	
	my_func_ptr = myAdd;
	printf("myAdd => %d\n",(*my_func_ptr)(5,3));
	
	my_func_ptr = &mySub;
	printf("mySub => %d\n",(*my_func_ptr)(5,3));
	
	call_a_func(do_math); 
	
	return(0);
}
