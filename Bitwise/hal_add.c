#include<stdio.h>

//example 13 (1101) + 10 (1010)
//        1101                          1101
//       ^1010                         &1010
//        0111 = 7把不須進位的保留住    1000 = 8 抓進位值，向左shift 1 位，如果是detect為1代表有進為要處理並與sum的結果一起帶入下次運算 
// 算到進位沒抓到1這樣就回傳sum就是答案   
/*
int add(int a,int b){
    
                
        while(b!=0){    
            int carry = a & b; 
            a = a ^ b;
            
            printf("%d %d %d\n",a,b,carry);           
            b = carry << 1;    // 把carry shift left 1給        
        }
        return(a);    
    
    }
*/ 

int add_recursive(int a,int b){
    
           if(b){
                 return( add_recursive(a ^ b, (a & b) << 1));
           }              
           return(a);
    }

int main(){
    
    int a,b;
    printf("a = ");
    scanf("%d",&a);
    printf("b = ");
    scanf("%d",&b);
    
    //printf("%d\n",add(a,b));    
    printf("%d\n",add_recursive(a,b));
    system("pause");
    return(0);
    
    }
