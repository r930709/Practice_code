#include<stdio.h>
#include<stdlib.h>


typedef struct stacknode NODE;

struct stacknode{
       
       int data;
       NODE *next;       
       
       };
NODE* push(NODE *push_node){
      
      int data = 0;
      NODE *head = NULL;
      if(push_node == NULL){
             
             push_node = (NODE *)malloc(1*sizeof(NODE));
             printf("\tinput data : ");      
             scanf("%d",&data);
             push_node->data = data;
             push_node->next = NULL;      
             return(push_node);      
                   }
      else{
           head = (NODE *)malloc(1*sizeof(NODE));
           printf("\tinput data: ");
           scanf("%d",&data);
           head->data = data;
           head->next = push_node;
           return(head);
           }
      
      }
NODE* pop(NODE *pop_node){
     
     NODE *temp_head = NULL;
     if(pop_node == NULL){printf("\tEmpty stack!!\n");  return(NULL);}
     else{
          temp_head = pop_node->next;
          printf("\tThe stack node %d pop!!\n",pop_node->data);
          free(pop_node);
          pop_node = NULL;
                   return(temp_head);
          }
     
     }

void show_nodes(NODE *stack_head){
     
     NODE *traversal_node = NULL;
     if(stack_head == NULL){printf("\tEmpty stack!!\n");}
     else{
          traversal_node = stack_head;
                while(traversal_node != NULL){
                      if(traversal_node->next == NULL){
                           printf("%d ->NULL\n",traversal_node->data);                          
                      }
                      else{                      
                      printf("%d ->",traversal_node->data); 
                      
                      } 
                      traversal_node = traversal_node->next;              
                        
                }
          
          }
     
     }
     
NODE* delete_last(NODE *stack_head){
     NODE *delete_node = NULL, *delete_previous = NULL;
     if(stack_head == NULL){printf("\tEmpty stack!!\n"); return(NULL);}
     else{
          delete_node = stack_head;
                if(delete_node->next==NULL){
                     printf("\tonly one node in this stack: %d ,and now delete it\n",delete_node->data);
                     delete_node = NULL;
                     free(stack_head);
                     stack_head = NULL;
                     return(NULL);
                }
                else{
                     while(delete_node->next!=NULL){
                          delete_previous = delete_node;
                          delete_node = delete_node->next;                         
                }
                     printf("\tThis is the stack last node : %d,previous node : %d\n",delete_node->data,delete_previous->data);
                     delete_previous->next = NULL;
                     free(delete_node);
                     delete_node = NULL;
                     return(stack_head);        
                }      
                       
          }
     
     }

NODE* reverse(NODE *stack_head){
      
      NODE *reverse_tra = NULL, *reverse_next = NULL,*reverse_temp = NULL; 
      if(stack_head == NULL){printf("\tEmpty stack!!\n"); return(NULL);}
      else{
          reverse_tra = stack_head;
                if(reverse_tra->next==NULL){
                     printf("\tonly one node in this stack: %d ,reverse no change,ingonre it\n",reverse_tra->data);
                     reverse_tra = NULL;
                     return(stack_head);
                }
                else{
                     reverse_next = reverse_tra->next;
                     reverse_tra->next = NULL;
                     while(reverse_next!=NULL){
                          if(reverse_next->next == NULL){
                               printf("\ttwo stack node\n");
                               reverse_next->next = reverse_tra;
                               return(reverse_next);
                          } 
                          else{
                               printf("\tat least three stack node\n");
                                reverse_temp = reverse_next->next;
                               while(reverse_temp->next!=NULL){
                                  
                                   reverse_next->next = reverse_tra;
                                   reverse_tra = reverse_next;
                                   reverse_next = reverse_temp;
                                   reverse_temp = reverse_temp->next;
                               }
                                   if(reverse_temp->next==NULL){
                                         reverse_next->next = reverse_tra;
                                         reverse_temp->next = reverse_next;
                                         return(reverse_temp);
                                   
                                   }
                               }
                          }
                                               
                     }
                      
                }
                
      }


int main(){
    
    int ch = 0;
    NODE *ptr = NULL;
        
    while(1){
        printf("choose function <1>psuh <2>pop <3>show all stack nodes <4>delete last <5>reverse :");
        scanf("%d",&ch);
              switch(ch){
                    case 1:
                           ptr = push(ptr);               
                           break;               
                    case 2:               
                           ptr = pop(ptr);
                           break; 
                    case 3:
                           show_nodes(ptr);               
                           break; 
                    case 4:               
                           ptr = delete_last(ptr);
                           break;
                    case 5:               
                           ptr = reverse(ptr);
                           break;
                    default:
                           printf("wrong input,try again\n");                
                           break;                            
                         
              }
    
    
    }
    system("pause");
    return(0);
    }
