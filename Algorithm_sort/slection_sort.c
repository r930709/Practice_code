#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10


/*The Sequence is {75,30,21,50,45,9,16,12,31,40},sort it from small to large
  Selection sort is that choosing the minimum data from the last sequence compare with the present data every time
  if minimum data smaller than the present data, we record the min_index and swap them each other
  do this behavior from head to tail      
*/
void swap(int *large,int *small){
              int tempdata = *small;
              *small = *large;
              *large = tempdata;     
     }

int Search_minimum_data(int *temp,int temp_head_index){
            int i,temp_head,min_index = 0;
                temp_head = *(temp+temp_head_index);
                for(i=temp_head_index+1;i<MAXSIZE;i++){
                     if(temp_head > *(temp+i) ){
                                  temp_head = *(temp+i);
                                  min_index = i;              
                     } 
                       
                }
                return(min_index);          //if there is no data in sequence smaller than the present data,we return 0
     }


void Selection_sort(int *temp){
     
     int i,min_index;
     
         for(i=0;i<MAXSIZE;i++){   //count index from head to tail
                 min_index = Search_minimum_data(temp,i);
                 //printf("min_index : %d\n",min_index);                                             
                 if(min_index){
                               swap((temp+i),(temp+min_index));
                 }
         }         
     
     }
     
   


int main(){
    
    int number[MAXSIZE]={75,30,21,50,45,9,16,12,31,40};
    
    int i;
      
        
            printf("Sequence before Selection sort :\n");
                for(i=0;i<10;i++){
                    if(i==9){printf("%d\n",number[i]);}
                    else{
                    printf("%d ->",number[i]);
                    }
                }
            
            Selection_sort(number);                               
                            
            
            printf("Sequence after Selection sort :\n");
                for(i=0;i<10;i++){
                    if(i==9){printf("%d\n",number[i]);}
                    else{
                    printf("%d ->",number[i]);
                    }
                }              
            
        
    
    system("pause");
    return(0);
    }
