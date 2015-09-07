#include<stdio.h>

int solve_n(int num){ 
        int x;
        /*if(!(num &0x01)){
            num--;           
        }*/   
        (num & 0x01) ? num: num--;  // The same meaning as above 
            
            num++;
            num = num >> 1;
            
            return(num);
    }

int main(){
    
    size_t num,temp,result;
    
        
    printf("input a number: ");
    scanf("%d",&num);
    
            result = solve_n(num);
            result *= result;           
    printf("sum =  %d\n",result);

    system("pause");                     
    return(0);
    }
