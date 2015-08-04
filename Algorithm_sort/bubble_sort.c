#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAXSIZE 10


/*The Sequence is {75,30,21,50,45,9,16,12,31,40},sort it from small to large
      The idea is that compare two adjacent elements, if the elements of the larger at front need to be exchanged.
      Repeat this behavior for every element in this sequence 
      i represents every element in this sequence from head to tail
      j represents to traversal and compare two adjacent elements 
      Use flag , it means that we could save time to compare, because if the sequence has been sorted ,the flag still be false
      and then we don't need to compare the sequence
*/
void swap(int *large,int *small){
              int tempdata = *small;
              *small = *large;
              *large = tempdata;     
     }


void Bubble_sort(int *temp){
     
     int i,j;
     
         for(i=0;i<MAXSIZE;i++){
               
               for(j=0;j<(MAXSIZE-1);j++){
                     if(*(temp+j) > *(temp+j+1)){
                             swap((temp+j),(temp+j+1));             
                     }
                     
               }
         }         
     
     }
     
void Bubble_sort_flag(int *temp){
     
     int i,j;
     int flag = 0;
          
         for(i=0;i<MAXSIZE;i++){
               
               for(j=0;j<(MAXSIZE-1);j++){
                     if(*(temp+j) > *(temp+j+1)){
                             swap((temp+j),(temp+j+1)); 
                             flag = 1;            
                     }
                     
               }
               if(!flag){ break; }
         }         
     
     }     


int main(){
    
    int number[MAXSIZE]={75,30,21,50,45,9,16,12,31,40};
    
    int i;
   
    
        
            printf("Sequence before Bubble sort :\n");
                for(i=0;i<10;i++){
                    if(i==9){printf("%d\n",number[i]);}
                    else{
                    printf("%d ->",number[i]);
                    }
                }
            
            Bubble_sort(number);                               
            //Bubble_sort_flag(number);                 
            
            printf("Sequence after Bubble sort :\n");
                for(i=0;i<10;i++){
                    if(i==9){printf("%d\n",number[i]);}
                    else{
                    printf("%d ->",number[i]);
                    }
                }              
            
        
    
    system("pause");
    return(0);
    }
