#include<stdio.h>
#include<stdlib.h>

//fib(n-1)+fib(n-2) = next_sum
//0,1,1,2,3,5,8,13.....,end of 46,47 will be overflow
int recursive(int num){
    
    int tempsum = 0;
        if(num<=0){return(0);}
        else if(num==1){return(1);}        
       return( recursive(num-1)+recursive(num-2)); 
      
    }


int main(){
    
    int count = 0;
        while(1){
                 printf("input number for recursive > ");
                 //scanf("%d",&count);       
                 if(recursive(count)>=0){                   
                     printf("The %d recursive result %d\n",count,recursive(count));
                     count++;
                 }
                 else{
                      printf("The %d recursive result %d,is overflow\n",count,recursive(count));
                      break;
                 }
        }
    system("pause");
        return(0);
    
}
