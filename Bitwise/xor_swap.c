#include<stdio.h>

void swap1(int *a,int *b){
     
         if(a!=b){          //Note the register address must be different
             *a = *a ^ *b;
             *b = *a ^ *b;
             *a = *a ^ *b;
         }else{
               printf("same memory address\n");      
         }
     
     }

/*
void swap2(int *a,int *b){
     
         if(a!=b){          //Note the register address must be different
            *a=*a^*b^(*b=*a);      //First direct give the value of a to *b,and then *a = (*a ^ *b) ^ *a¡iget the value of b¡j 
         }else{
               printf("same memory address\n");      
         }
     
     }
*/

//#define  swap3(a,b)   ((a)^=(b),(b)^=(a),(a)^=(b))

/*
void swap4(int *a,int *b){  //a algorithm is like xor swap
                            //the idea is that use sum of the *a,*b to compare each other to get the different value                    
           *a = *a + *b;
           *b = *a - *b;
           *a = *a - *b;             
         
     
     }
*/

int main(){
    
    int x = 5,y =12;
    printf("original : x = %d,y = %d\n",x,y);
    swap1(&x,&y); 
    //swap2(&x,&y);    
    //swap3(x,y);  
    //swap4(&x,&y);
    printf("after swap x = %d,y = %d\n",x,y); 
    
    system("pause");
    return(0);
    }
