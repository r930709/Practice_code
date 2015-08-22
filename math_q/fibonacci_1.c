#include<stdio.h>
#include<stdlib.h>

//fib(n-1)+fib(n-2) = next_sum
//0,1,1,2,3,5,8,13.....,end of 46,47 will be overflow
int iterative(int num){
    int previous_1 = -1, previous_2 = 1 ;   
    int i,temp_sum = 0;
        
                
            for(i=0;i<=num;i++){
             
                temp_sum = previous_1 + previous_2;
                previous_1 = previous_2;
                previous_2 = temp_sum;                                         
            }
           
        return(temp_sum);
    }


int main(){
    
    int count = 0;
        while(1){
                 printf("input number for iterative > ");
                 //scanf("%d",&count);       
                 if(iterative(count)>=0){                   
                     printf("The %d iterative result %d\n",count,iterative(count));
                     count++;
                 }
                 else{
                      printf("The %d iterative result %d,is overflow\n",count,iterative(count));
                      break;
                 }
        }
    system("pause");
        return(0);
    
    
    }
