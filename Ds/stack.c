#include<stdio.h>
#include<stdlib.h>

typedef struct stack_node NODE;
struct stack_node{
       
       int data;
       NODE *nextpoint;
       };

NODE* push_node(NODE *node){
     int data = 0;
     NODE *next = NULL;
     if(node == NULL){         //check whether there is a head
            NODE *node = (NODE *)malloc(sizeof(NODE));
            printf("input data to the stack node: ");
            scanf("%d",&data);
            node->data = data;
            node->nextpoint = NULL;
            return(node);          
     }
     else{
      next = (NODE *)malloc(sizeof(NODE));  
           printf("input data to the stack node: ");
           scanf("%d",&data);
           next->data = data;
           next->nextpoint = node; 
           return(next);                  
          }       
}

NODE* pop_node(NODE *pop_node){
      NODE *temp_node = NULL;
      if(pop_node == NULL){printf("no node in stack\n");return(NULL);}
      else{
           temp_node = pop_node->nextpoint;
           printf("The top of stack %d pop!!\n",pop_node->data);
           free(pop_node);
           pop_node = NULL;    
           return(temp_node);
      }
      
}

void show_node(NODE *head){
     NODE *traversal_node = NULL;
     if(head == NULL){printf("no node in stack\n");}
     else{
          traversal_node = head;
          while( traversal_node!=NULL){
                 printf("%d\n",traversal_node->data);
                 traversal_node = traversal_node->nextpoint;
                 }    
                   
     }     
}

int main(){
    NODE *ptr = NULL;
    int ch;
    
    while(1){  
        printf("choose stack function <1>push <2>pop <3>show all nodes :");
        scanf("%d",&ch);
        switch(ch){
               case 1:
                      ptr = push_node(ptr);
                      //printf("ptr->data:%d ptr->next:%p\n",ptr->data,ptr->nextpoint);                  
                      break;   
               case 2:
                      ptr = pop_node(ptr);
                      break;
               case 3:
                      show_node(ptr);
                      break;                          
               default:
                       printf("wrong input,try again\n");    
        
        }    
    }
    system("pause");
    return(0);
    }
