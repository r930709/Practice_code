#include<stdio.h>

//example 13 (1101) + 10 (1010)
//        1101                          1101
//       ^1010                         &1010
//        0111 = 7�⤣���i�쪺�O�d��    1000 = 8 ��i��ȡA�V��shift 1 ��A�p�G�Odetect��1�N���i���n�B�z�ûPsum�����G�@�_�a�J�U���B�� 
// ���i��S���1�o�˴N�^��sum�N�O����   
/*
int add(int a,int b){
    
                
        while(b!=0){    
            int carry = a & b; 
            a = a ^ b;
            
            printf("%d %d %d\n",a,b,carry);           
            b = carry << 1;    // ��carry shift left 1��        
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
