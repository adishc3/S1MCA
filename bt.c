#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int data)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("mem alloc failed");
        exit(1);
    }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
void insert()
{
    struct node *temp,*newnode;
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    remp=root;
    printf
    if(temp==NULL)
    {
        temp=newnode;
        return;
    }


}
