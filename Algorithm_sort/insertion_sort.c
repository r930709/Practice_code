#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10


/*The Sequence is {75,30,21,50,45,9,16,12,31,40},sort it from small to large
      Idea is  that the sequence is divided into two parts(sorted(left) and unsorted(right))
      and then use a temp variable to store the index data.
      i for index, j for traversal from head to tail.
                    #  ! 
      i = 1, j = 0 75,30,21...  , j++ until find tempdata <= *(temp+j),and j is the position to insert 
                                  Remeber: shift right from j to i at first and last insort the tempdata to index of j of array                         
                    #     ! 
      i = 2, j = 0 30,75,21...


*/
void Insertion_sort(int *temp){
     
     int i,j,k,tempdata = 0;
     
         for(i=1;i<MAXSIZE;i++){
               
               k = i;
               j = 0;
               tempdata = *(temp+i);
               while((tempdata > *(temp+j)) && (j <= (MAXSIZE-1))){  //until find tempdata <= *(temp+j),and j is the position to insert 
                       j++;
               }
               
               while(k>j){   //shift right from j to i at first and last insort the tempdata to index of j of array 
                       *(temp+k) = *(temp+k-1);
                       k--;
               }
               *(temp+j) = tempdata;              
         }     
     
     }


int main(){
    
    int number[MAXSIZE]={75,30,21,50,45,9,16,12,31,40};
    
    int i;
    printf("Sequence before insertion sort :\n");
        for(i=0;i<10;i++){
            if(i==9){printf("%d\n",number[i]);}
            else{
            printf("%d ->",number[i]);
            }
        }
    
    Insertion_sort(number);
    
    printf("Sequence after insertion sort :\n");
        for(i=0;i<10;i++){
            if(i==9){printf("%d\n",number[i]);}
            else{
            printf("%d ->",number[i]);
            }
        }
    
        
    
    system("pause");
    return(0);
    }
