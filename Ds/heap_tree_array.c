#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 25
int heap_tree[MAXSIZE];
int last_index = 0;

void swap(int *smaller,int *larger){
     int temp = *smaller;
     *smaller = *larger;
     *larger = temp;              
     
     }

void adjust_up(int last){
         
         //printf("last_index : %d\n",last);
         if(last/2 > 0){
                while(last>1){
                    if(heap_tree[last/2] < heap_tree[last]){
                                //printf("p :%d c:%d\n",heap_tree[last/2],heap_tree[last]);
                                swap(&heap_tree[last/2],&heap_tree[last]);         
                    }else{      break;     }
                    last /=2; 
                }            
         }        
     
     }
void adjust_down(int temp[],int index,int last){
         int temp_root = temp[index];
         int temp_children = index*2;
         
         while(temp_children <= last){
                    if((temp_children < last) && (temp[temp_children] < temp[temp_children+1])){
                                      temp_children++;                  
                    }
                    if(temp_root >= temp[temp_children]){
                                 break;
                    }else{
                          temp[temp_children/2] = temp[temp_children];
                          temp_children *=2;
                    }
                                                                 
         }          
         temp[temp_children/2] = temp_root;           
     
     }     

void Insert_heap_node(){
     
         int data,i;
         printf("input node data: ");
         scanf("%d",&data);
         if(last_index <= MAXSIZE){    
                       heap_tree[++last_index] = data;
                       adjust_up(last_index);
         }
     
                   
     }

int Search_heap_tree(int del_data){
               
           int i;    
               if(last_index > 0){
                     for(i=1;i<=last_index;i++){
                           if(heap_tree[i] == del_data){
                                        return(i);                   
                           }
                     }        
               
               }else{
                    printf("Heap tree empty!!\n");
                    return(0);      
               }
               printf("No delete data in this heap tree\n");        
               return(0);
    }
     
     
void Delete_heap_node(){
            
            int del_data,del_index;
            printf("Delete heap node data: ");
            scanf("%d",&del_data);            
            
            if((del_index=Search_heap_tree(del_data))!=0){
                     heap_tree[del_index] = heap_tree[last_index];
                     heap_tree[last_index] = 0;
                     last_index--;                                          
            }
            
     }     

void Show_heap_tree(int ch){
            
         int heap_temp[MAXSIZE];
         int i,j;
         
         if(last_index>0){
             for(i=1;i<=MAXSIZE;i++){
                    heap_temp[i] = heap_tree[i];               
             }
             printf("last_index : %d\n",last_index);
             for(i=last_index-1;i>0;i--){
                    swap(&heap_temp[1],&heap_temp[i+1]);
                    adjust_down(heap_temp,1,i);
             }
             switch(ch){
                        case 1:
                               for(j=1;j<=last_index;j++){
                                      printf("%d->",heap_temp[j]);                    
                               }
                               printf("\n");
                               break;
                        case 2:
                               for(j=last_index;j>0;j--){
                                      printf("%d->",heap_temp[j]);                    
                               }
                               printf("\n");
                               break;
                        default:
                               printf("Wrong choice!!\n");
                               break;             
             
             }             
         }else{
               printf("Empty heap tree\n");      
         }
     }




int main(){
    
    int ch,ch_show,enter=1;
    int i;
    
    while(enter){
        printf("Enter your choice <1>Insert heap node <2>Delete heap node <3> show all heap node <4>Quit: " );
        scanf("%d",&ch);
        
        switch(ch){
               case 1:
                      Insert_heap_node();
                      for(i=1;i<MAXSIZE;i++){
                             printf("%d->",heap_tree[i]);                
                      }
                      break;
               case 2:
                      Delete_heap_node();
                      break;
               case 3:
                      printf("<1>Increase <2>Decrease : ");
                      scanf("%d",&ch_show);
                      Show_heap_tree(ch_show);
                      break;
               case 4:
                      enter = 0;
                      break;           
               default:
                       break;    
        }
    }
    system("pause");
    return(0);
    }
