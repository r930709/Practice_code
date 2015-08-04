#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

int number[MAXSIZE]={75,30,21,50,45,9,16,12,31,40};
int temp[MAXSIZE];

void mergesort(int left,int right){
     
     int i,j,k;
     int mid = (left + right)/2;
        
         
         for(i=left,j=(mid+1),k=0;i<=(mid) || j<=(right);k++){
         
             if(i>mid){
                  temp[k] = number[j++];
             }
             else if(j>(right)){
                  temp[k] = number[i++];
                  
             }else if(number[i]<=number[j]){
                   temp[k] = number[i++];
                   
             }
             else{
                  temp[k] = number[j++];
                  
             }
         }
         for(i=left,k=0;i<=right;i++,k++){
             number[i] = temp[k];               
         }
     
     }


void partition(int left,int right){
     
     int mid = (left + right)/2;
         if(left < right){
              partition(left,mid);
              partition(mid+1,right);
              mergesort(left,right);
         }
     
     
     }


int main(){
    
    int i;
    printf("Sequence before merge sort :\n");
    for(i=0;i<10;i++){
        if(i==9){printf("%d\n",number[i]);}
        else{
        printf("%d ->",number[i]);
        }
    }    
    
    
    partition(0,9);
    printf("Sequence after merge sort :\n");
    for(i=0;i<10;i++){
        if(i==9){printf("%d\n",number[i]);}
        else{
        printf("%d ->",number[i]);
        }
    }
    
    system("pause");
    return(0);
      }
