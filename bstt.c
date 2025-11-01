#include<stdio.h>
#include<stlib.h>
struct node
{
    int info;
    struct node *left;
    struct node *right;
}:
struct node *root=NULL;

struct node *ins(struct node *root,int data)
{
    if(root==NULL)
    {
        struct node *newnode=(struct node)malloc(sizeof(struct node));
        newnode->info=data;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if(data==root->info)
    {
        printf("ELEMENT ALREADY EXISTS\n");
    }
    else if(data<root->info)
    {
        root->left=ins(root->left,data);
    }
    else
    {
        root->right=ins(root->right,data);
    }
    return root;
}

struct node *minvalnode(struct node *node)
{
    struct node *current=node;
    while(current&&current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}