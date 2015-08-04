#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10
#define Merge_MAXSIZE 20

/*Two sorted sequence merge to a Sequence from small to large
  One sequence is {75,30,21,50,45,9,16,12,31,40},sort it{9 12 16 21 30 31 40 45 50 75 }
  The other sequence is {100,14,18,43,28,77,57,66,88,11} sort it {11 14 18 28 43 57 66  77 88 100}
  Use selection sort to sort two sequence and then use merge sort to sort two sequence to becoma a sequence from small to large.    
*/




int number[MAXSIZE]={75,30,21,50,45,9,16,12,31,40};
int number2[MAXSIZE]={100,14,18,43,28,77,57,66,88,11};
int temp[Merge_MAXSIZE]={0};
int temp_2[Merge_MAXSIZE]={0};

void mergesort(int left,int right){
     
     int i,j,k;
     int mid = (left + right)/2;
        //printf("left %d right %d\n",left,right);
         
         for(i=left,j=(mid+1),k=0;i<=(mid) || j<=(right);k++){
            // printf("\ni %d j %d mid %d\n",i,j,mid);
             if(i>mid){
                 // printf("\ni %d, mid %d\n",i,mid);
                  temp_2[k] = temp[j++];
                  
             }
             else if(j>(right)){
                 // printf("\nj %d, mid %d\n",j,mid);
                  temp_2[k] = temp[i++];
                  
             }
             else if(temp[i]<=temp[j]){
                   temp_2[k] = temp[i++];
                  // printf("com1 %d\n",temp[k]);
             }
             else{
                  temp_2[k] = temp[j++];
                 // printf("com2 %d\n",temp[k]);
             }
         }
         for(i=left,k=0;i<=right;i++,k++){
             temp[i] = temp_2[k];
             //printf("%d ->",number[i]);               
         }
     
     }

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


/*
void partition(int left,int right){
     
     int mid = (left + right)/2;
         printf("mid!! %d\n",mid);
         if(left < right){
              partition(left,mid);
              partition(mid+1,right);
              mergesort(left,right);
         }
     
     
     }
*/

int main(){
    
    int i;
    printf("Sequence 1 before selection sort :\n");
    for(i=0;i<MAXSIZE;i++){
        if(i==9){printf("%d\n",number[i]);}
        else{
        printf("%d ->",number[i]);
        }
    }    
    Selection_sort(number); 
    printf("Sequence 1 after selection sort :\n");
    for(i=0;i<MAXSIZE;i++){
        if(i==9){printf("%d\n",number[i]);}
        else{
        printf("%d ->",number[i]);
        }
        temp[i] = number[i];
    } 
    
    printf("Sequence 2 before selection sort :\n");
    for(i=0;i<MAXSIZE;i++){
        if(i==9){printf("%d\n",number2[i]);}
        else{
        printf("%d ->",number2[i]);
        }
    } 
    Selection_sort(number2); 
    printf("Sequence 2 after selection sort :\n");
    for(i=0;i<MAXSIZE;i++){
        if(i==9){printf("%d\n",number2[i]);}
        else{
        printf("%d ->",number2[i]);
        }
        temp[MAXSIZE+i] = number2[i];
    }
    
    printf("Sequence before merge two sequence sort :\n");
    for(i=0;i<Merge_MAXSIZE;i++){
        if(i==(Merge_MAXSIZE-1)){printf("%d\n",temp[i]);}
        else{
        printf("%d ->",temp[i]);
        }
    }
    //partition(0,9);
    mergesort(0,Merge_MAXSIZE-1);
    printf("Sequence after merge two sequence sort :\n");
    for(i=0;i<Merge_MAXSIZE;i++){
        if(i==(Merge_MAXSIZE-1)){printf("%d\n",temp[i]);}
        else{
        printf("%d ->",temp[i]);
        }
    }
    
    system("pause");
    return(0);
      }
