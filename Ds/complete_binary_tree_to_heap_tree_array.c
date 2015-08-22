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

int adjust_up(int temp[],int last_parent,int last){
         
         int temp_last_parent = temp[last_parent];
         int last_parent_left_child = last_parent*2;
         //printf("last_index : %d\n",last);
         
                if(last_parent>=1){
                    if(((last_parent_left_child <= last) && (last_parent_left_child+1 <= last)) && temp[last_parent_left_child] < temp[last_parent_left_child+1]){
                                //printf("p :%d c:%d\n",heap_tree[last/2],heap_tree[last]);
                                last_parent_left_child++;         
                    }
                    if(temp[last_parent] >= temp[last_parent_left_child]){
                                printf("no adjust up\n");
                                return(0);        
                    }else{
                          temp[last_parent] = temp[last_parent_left_child];
                          temp[last_parent_left_child] = temp_last_parent;
                          return(last_parent_left_child);
                    }
                    
                     
                }else{      
                            printf("no adjust up\n");
                            return(0);
                                                
                }            
                 
     
     }
void adjust_down(int temp[],int index,int last){
         int temp_root = temp[index];
         int temp_children = index*2;
         
         
         if(temp_children <= last){
                 while(temp_children <= last ){
                            if(((temp_children <= last) && (temp_children+1 <= last)) && (temp[temp_children] < temp[temp_children+1])){
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
         }else{
               printf("no adjust down\n");
         }       
     }     

void Adjust_heap_tree(int temp[],int last){
              
            int temp_last = last;
            int temp_last_parent = last/2;
            int swap_child_index = 0;
            int i;
                while(temp_last_parent>=1){
                        swap_child_index = adjust_up(heap_tree,temp_last_parent,last);
                        //printf("swap_child_index : %d",swap_child_index);
                        
                        if(swap_child_index!=0){
                             adjust_down(heap_tree,swap_child_index,last);
                        }
                        
                        temp_last_parent--; 
                }                 
     
     }

void Insert_heap_node(){
     
         int data,i;
         printf("input node data: ");
         scanf("%d",&data);
         if(last_index <= MAXSIZE){    
                       heap_tree[++last_index] = data;
                       //adjust_up(last_index);
         }
     
                   
     }

void Heap_sort(int temp[],int last){
               
               int i;
               if(last >= 1){
                      while(last>1){
                        // printf("last : %d\n",last);                              
                         swap(&temp[1],&temp[last]);                         
                         last--;
                         Adjust_heap_tree(heap_tree,last);                          
                      }   
               }else{
                     printf("Empty heap tree\n");      
               }
     }

     

int main(){
    
    int ch,ch_show,enter=1;
    int i;
    
    while(enter){
        printf("<1>Insert a complete binary tree node \n");
        printf("<2>Become a Max heap tree \n");//<2>Delete heap node <3> show all heap node  " );
        printf("<3>Heap sort \n");
        printf("<4>Quit ");
        printf("Enter your choice $ ");
        
        scanf("%d",&ch);
        
        switch(ch){
               case 1:
                      Insert_heap_node();
                      for(i=1;i<=last_index;i++){
                             printf("%d->",heap_tree[i]);                
                      }
                      break;
               case 2:
                      Adjust_heap_tree(heap_tree,last_index);
                      for(i=1;i<=last_index;i++){
                             printf("%d->",heap_tree[i]);                
                      }
                      break;
               case 3:
                      Heap_sort(heap_tree,last_index);
                      for(i=1;i<=last_index;i++){
                             printf("%d->",heap_tree[i]);                
                      }
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
