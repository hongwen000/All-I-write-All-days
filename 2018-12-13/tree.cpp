#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>
typedef struct Node {
    struct Node *left;
    struct Node *right;
    int value;
} Node;
Node* create_node(int value)
{
  Node* rootp=(Node*)(malloc(sizeof(Node)));
  rootp->value = value;
  rootp->left = NULL;
  rootp->right = NULL;
  return rootp; 
}
Node* init_root(int value){
    return create_node(value);
}

void insert_node(Node * p, int value){
    if(value < p->value)
        if(!p->left)
        {
            Node* new_p = create_node(value);
            p->left = new_p;
        }
        else
           insert_node(p->left, value);
    else 
        if(!p->right)
        {
            Node* new_p = create_node(value);
            p->right = new_p;
        }
        else
           insert_node(p->right, value);
}
void traverse_tree_inorder(Node *p){
  if (p != NULL){
        traverse_tree_inorder(p->left);
        printf("%d ",p->value);
        traverse_tree_inorder(p->right);
    }
}
void recycle_nodes(Node *p){
  if (p != NULL){
        recycle_nodes(p->left);
        recycle_nodes(p->right);
        free(p);
    }
}
