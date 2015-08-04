#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

// swap two array data,not address
void swap(int *larger,int *smaller){
     int temp;
     temp = *larger;
     *larger = *smaller;
     *smaller = temp;
     
     }

//this is simple quicksort ,sort the sequence from smaller to larger, I choose the far left array data to become the target
void quicksort(int *temp,int left,int right){
     
     int pivot,i,j;
     
     // check end of the divide 
     if(left>=right){return;}  
     
         pivot = temp[left]; //choose target to compare the (i,j) ,and sort them
         i = left + 1;
         j = right;
           while(1){
               while(i<=right){ //find from left sequence,if one of array data larger than target,then mark the index,later swap it
                                // it's because we wnat temp[i] equal smaller than the target
                    if(temp[i]>pivot){  
                         break;                         
                         }
                    i++;               
               }  
               while(j>left){  //find from right sequence,if one of array data smaller than target,then mark the index,later swap it
                               // it's because we wnat temp[j] equal larger than the target
                    if(temp[j]<pivot){
                         break;                         
                         }           
                    j--;          
               
               }        
               if(i>j){break;}  //find all of the temp sequence
               
               swap(&temp[i],&temp[j]);   //swap the (temp[i],temp[j]),for the sequence from smaller to largger
           }
           swap(&temp[left],&temp[j]);    //End of temp sequence,then prepare to change the new target, 
                                          //so swap the (temp[left],temp[j]),for the sequence from smaller to largger                             
           
         quicksort(temp,left,j-1);   //divide
         quicksort(temp,j+1,right);
           
         
     }

int main(){
    
    int number[MAXSIZE]={75,30,21,50,45,9,16,12,31,40};
    int i;
    
    printf("Sequence before quick sort :\n");
        for(i=0;i<10;i++){
            if(i==9){printf("%d\n",number[i]);}
            else{
            printf("%d ->",number[i]);
            }
        }
    
        quicksort(number,0,(MAXSIZE-1));
    printf("Sequence after quick sort :\n");
        for(i=0;i<10;i++){
            if(i==9){printf("%d\n",number[i]);}
            else{
            printf("%d ->",number[i]);
            }
        }             
    
    system("pause");
    return(0);
    }
