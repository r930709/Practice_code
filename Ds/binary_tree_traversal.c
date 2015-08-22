#include<stdio.h>
#include<stdlib.h>

/*Show three kinds of traversal of the binary tree
---Example:
       Input tree node sequence is{3,9,5,10,4,7,8,1,15,16},if data>root put right,else put left
                                   3
                                 1    9
                                    5   10                   
                                  4  7     15
                                      8       16       
       1.inorder traversal,      
       2.preorder traversal,
       3.postorder traversal,

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
void Preorder_traversal(TRnode *root){
           if(root == NULL){return;}
            else{
                 printf("\t%d",root->data);
                 Preorder_traversal(root->left);                 
                 Preorder_traversal(root->right);     
                 
            }                    
     }           

void Postorder_traversal(TRnode *root){
           if(root == NULL){return;}
            else{
                 
                 Postorder_traversal(root->left);                 
                 Postorder_traversal(root->right);     
                 printf("\t%d",root->data);
            }                    
     }
    
//------Delete idea, use Postorder_traversal method,from bottom to top ,from left to right-------//     
int Delete_node(TRnode *root,TRnode *parent_node){
          int count = 0;           
          if(root == NULL){return(0);}
            else{
                 
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
    
    int i,nu,data,count;
    TRnode *root = NULL;
    
    printf("Please input the number of node : ");
    scanf("%d",&nu);
    
        for(i=0;i<nu;i++){
           printf("input data :");
           scanf("%d",&data);                
           root = Add_tree_node(root,data);              
        
        }
    printf("Inorder traversal : \n");
            Inorder_traversal(root);    
    printf("Preorder traversal : \n");
            Preorder_traversal(root);    
    printf("Postorder traversal : \n");
            Postorder_traversal(root);
    printf("[Delete all of tree node..]\n");
    count = Delete_node(root,root);
    printf("The number of deleted node is : %d\n",count);
    
    
    
    system("pause");
    return(0);
    }
