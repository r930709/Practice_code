#include<stdio.h>
#include<stdlib.h>

double sqrt(int x){
       double diff = 0.00001;
       
       double low , high , mid ;
       
       if(x<0) {return(-1);}
       else if(0<x && x<1) { low = 0; high = 1; }
       else{ low = 1; high = x; } 
       
       while( high - low > diff ){
                
                mid = low + ((high - low)/2);
                if( (mid*mid) > x) high = mid;
                else low = mid;
                }
       return( low + diff );
       
       }


int main(){
    
    int input ;
    double sqrt_result;
    
    while(1){
    printf("input : ");    
    scanf("%d",&input);
    
    sqrt_result = sqrt(input);
    if(sqrt_result == -1) { printf("input is negative!!\n");}   
                   else{
                    printf(" %d sqrt is : %4.3f\n",input,sqrt_result);
                    }
    }
    
    system("pause");
    return(0);
    
    }
