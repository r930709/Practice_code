#include<stdio.h>
#include<stdlib.h>
#define Maxsize 5

typedef struct adjacency_node ADNode;
typedef struct vertex_head VHead;
typedef struct graph Graph;


struct adjacency_node{
       int data;
       ADNode *next;
              
       };



struct vertex_head{
       
       ADNode *head;
       };


struct graph{
       int Vertex_size;
       VHead *graph_head_index;      
       
       };
/*------------------------------------------------------------*/ 

Graph* Create_graph(Graph *ptr){
       
           int i;
           VHead *temp = NULL;
           if(ptr == NULL){
                  ptr = (Graph*)malloc(1*sizeof(Graph));
                  ptr->Vertex_size = Maxsize;
                  ptr->graph_head_index = (VHead* )malloc(Maxsize*(sizeof(VHead)));
                  
                  for(i=0; i<(ptr->Vertex_size);i++){
                        
                        //TWO ways write this
                        //1.point, arrow
                        temp = ptr->graph_head_index+i;                        
                        temp->head = NULL;
                        //2.array, dot                        
                        //ptr->graph_head_index[i].head = NULL;
                        
                  }
                  
           }
           return(ptr);            
       }
void Addedge_behavior(Graph *temp_g,int index,int position){           
             ADNode *newnode = NULL, *traversal = NULL;              
             VHead *temp_head = NULL;
             newnode = (ADNode*)malloc(1*sizeof(ADNode));
             newnode->data = position;
             newnode->next = NULL;
             
             temp_head = temp_g->graph_head_index+index;
             if(temp_head->head == NULL ){   temp_head->head = newnode;}
             else{
                  traversal = temp_head->head;
                  while(traversal->next!=NULL){                                                 
                                             
                        traversal = traversal->next; 
                  }
                  traversal->next = newnode;
                     
             }                                         
     }
/*-----------method 1 for symmetric matrix-----------------*/       
void Addedge(Graph *temp_g,int i,int j){
                        
             Addedge_behavior(temp_g,i,j);
             Addedge_behavior(temp_g,j,i);         
     }
     
/*-----------method 2 for normal matrix--------------------*/         
void Addedge_2(Graph *temp_g,int i,int j){
     
             Addedge_behavior(temp_g,i,j);
                     
     }
     
void Draw_Adjacencylist(Graph *temp_g){
             
             int i;
             VHead *temp_head = NULL;
             ADNode *traversal = NULL;
             
             for(i=0;i<temp_g->Vertex_size;i++){
                   temp_head = temp_g->graph_head_index+i;
                   printf("\nGraph[%d] : ",i);
                  if( temp_head->head == NULL){
                      
                      printf("[No data in this column]\n");
                      }
                  else{
                       traversal = temp_head->head;
                       
                       while(traversal->next!=NULL){
                             printf("%d->",traversal->data);
                             traversal = traversal->next;                                  
                       }
                       if(traversal->next == NULL){  printf("%d\n",traversal->data); } 
                  }                         
             }
                              
     
     }      
       
       


int main(){
    
    //special matrix,symmetric matrix 
    //int a[5][5] = {{0,1,0,0,1},{1,0,1,1,1},{0,1,0,1,0},{0,1,1,0,1},{1,1,0,1,0}};    
    //normal matrix,random matrix
    int a[5][5] = {{0,1,1,0,1},{1,0,0,0,1},{0,1,1,1,0},{0,1,0,0,1},{1,1,1,1,0}}; 
         
    int i,j;
    
    Graph *ptr = NULL; 
         ptr = Create_graph(ptr);
    
    printf("Show matrix : \n");
           for(i=0;i<Maxsize;i++){
                  for(j=0;j<Maxsize;j++){
                        
                        printf("%d\t",a[i][j]);
                        
                  }          
                  printf("\n");
           }
           
    printf("¡iShow matrix¡j.... \n");
    /*
    //------------method 1 for symmetric matrix------------------------------      
           for(i=0;i<Maxsize;i++){
                  for(j=i;j<Maxsize;j++){   // j = i for symmetrix matrix
                                           
                        if(a[i][j]== 1){
                                    
                               Addedge(ptr,i,j);                        
                        }
                  }  
                  
           }
    */
    //------------method 2 for symmetric matrix------------------------------
    
           for(i=0;i<Maxsize;i++){
                  for(j=0;j<Maxsize;j++){   // j = i for symmetrix matrix
                                           
                        if(a[i][j]== 1){
                                    
                               Addedge_2(ptr,i,j);                        
                        }
                  }          
                  
           }   
    printf("Show Adjacencylist : \n");
           Draw_Adjacencylist(ptr);           
        
    system("pause");
    return(0);
    }
