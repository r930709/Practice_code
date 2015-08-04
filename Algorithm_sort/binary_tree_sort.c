#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 10

/*Show three kinds of traversal of the binary tree
---Example:
       /*The Sequence is {75,30,21,50,45,9,16,12,31,40},sort it from small to large
       if data>root put right,else put left
                                     
       inorder traversal 
       

*/


typedef struct tree_node TRnode;

struct tree_node{
       
       int data;
       TRnode *left;
       TRnode *right;
       
       };
      
       
TRnode* Add_tree_node(TRnode *treenode,int data){
                    
                      
           if(treenode == NULL){
                                              
                  treenode = (TRnode*)malloc(1*sizeof(TRnode));
                  
                  treenode->data = data;
                  treenode->left = NULL;
                  treenode->right = NULL;           
                  
           }
           else{
                                  
                  if(data > (treenode->data)){
                      treenode->right = Add_tree_node(treenode->right,data);
                  }
                  else{
                      treenode->left = Add_tree_node(treenode->left,data);
                  }
                
           }
           return(treenode);
      
      
      }
      
void Inorder_traversal(TRnode *root){
     
            if(root == NULL){return;}
            else{
                 Inorder_traversal(root->left);
                 printf("\t%d",root->data);
                 Inorder_traversal(root->right);     
                 
            }
     
     }
    
//------Delete idea, use Postorder_traversal method,from bottom to top ,from left to right-------//     
int Delete_node(TRnode *root,TRnode *parent_node){
                     
          int count = 0;           
          if(root == NULL){return 0;}
            else{
                 //printf("count : %d\n",count);
                 count = count + Delete_node(root->left,root);                 
                 count = count + Delete_node(root->right,root);     
                 printf("\tThis tree node %d wil be deleted \n",root->data);
                 if((parent_node->data) < (root->data)){
                        parent_node->right = NULL;
                                                              
                 }
                 else{
                       parent_node->left = NULL;
                 }
                        free(root);
                        root = NULL;
                        count++;
                        
            }
            return(count);              
                  
    }    
     

int main(){
    
    int i,count;
    int number[MAXSIZE]={75,30,21,50,45,9,16,12,31,40};
    TRnode *root = NULL;
    
    printf("Sequence before Binary tree sort :\n");
                for(i=0;i<MAXSIZE;i++){
                    if(i==(MAXSIZE-1)){printf("%d\n",number[i]);}
                    else{
                    printf("%d ->",number[i]);
                    }
                }
    
        for(i=0;i<MAXSIZE;i++){
                          
           root = Add_tree_node(root,number[i]);              
        
        }
    printf("Sequence after Binary tree sort¡iInorder tracersal¡j :\n");
            Inorder_traversal(root);    
    printf("[Delete all of tree node..]\n");
    count = Delete_node(root,root);
    printf("The number of deleted node is : %d\n",count);
    
    
    
    system("pause");
    return(0);
    }
