#include<stdio.h>
#include<string.h>

typedef char * (*String_search)(const char *,int);

double cm_to_inches(double cm){
	return( cm/ 2.54);
}

int main(){
	double (*func1)(double) = cm_to_inches;
	
	String_search func2 = strchr;
	
		
	printf("%f %s\n",func1(15.0),func2("wikipedia",'i'));

	return(0);
}
