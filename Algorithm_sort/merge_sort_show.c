#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

/*The Sequence is {75,30,21,50,45,9,16,12,31,40},sort it from small to large
  Merge sort is a recursive algorithm that continually splits a list in half. If the list is empty or has one item, it is sorted by definition[from small to large].
               #  
  75 30 21 50 45/ 9 16 12 31 40    mid = (0,9)/2 = 4
         #  
  75 30 21/ 50 45/ 9 16 12 31 40    mid = (0,4)/2 = 2
      #  
  75 30/ 21/ 50 45/ 9 16 12 31 40    mid = (0,2)/2 = 1
   #  
  75/ 30/ 21/ 50 45/ 9 16 12 31 40    mid = (0,1)/2 = 0
  -----------merge sort---------------------------------
                        #  
  21 30 45 50 75/ 9 16 12/ 31 40    mid = (5,9)/2 = 7  
                     #  
  21 30 45 50 75/ 9 16/ 12/ 31 40    mid = (5,7)/2 = 6
                  #  
  21 30 45 50 75/ 9/ 16/ 12/ 31 40    mid = (5,7)/2 = 5
  -----------merge sort---------------------------------
  21 30 45 50 75/ 9 12 16 31 40
  -----------merge sort---------------------------------
  9 12 16 21 30 31 40 45 50 75      
  divide-and-conquer 
      
*/


int number[MAXSIZE]={75,30,21,50,45,9,16,12,31,40};
int temp[MAXSIZE];

void mergesort(int left,int right){
     
     int i,j,k;
     int mid = (left + right)/2;
        printf("left %d right %d\n",left,right);
         
         for(i=left,j=(mid+1),k=0;i<=(mid) || j<=(right);k++){
             printf("\ni %d j %d mid %d\n",i,j,mid);
             if(i>mid){
                  printf("\ni %d, mid %d\n",i,mid);
                  temp[k] = number[j++];
                  
             }
             else if(j>(right)){
                  printf("\nj %d, mid %d\n",j,mid);
                  temp[k] = number[i++];
                  
             }
             else if(number[i]<=number[j]){
                   temp[k] = number[i++];
                   printf("com1 %d\n",temp[k]);
             }
             else{
                  temp[k] = number[j++];
                  printf("com2 %d\n",temp[k]);
             }
         }
         for(i=left,k=0;i<=right;i++,k++){
             number[i] = temp[k];
             printf("%d ->",number[i]);               
         }
     
     }


void partition(int left,int right){
     
     int mid = (left + right)/2;
         printf("mid!! %d\n",mid);
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
