#include<stdio.h>
#include<stdlib.h>
struct node
{
    int info;
    struct node *right;
    struct node *left;
};
struct node *root=NULL;

struct node *insert(struct node *root,int data)
{
    if(root==NULL)
    {
        struct node *newnode=(struct node*)malloc(sizeof(struct node));
        newnode->info=data;
        newnode->left=NULL;
        newnode->right=NULL;
        return newnode;
    }
    if(data==root->info)
    {
        printf("The number already EXISTS!!!\n");
    }
    else if(data<root->info)
    {
        root->left=insert(root->left,data);
    }
    else
    {
        root->right=insert(root->right,data);
    }
    return root;
}

struct node *minvaluenode(struct node *node)
{
    struct node *current=node;
    while(current&&current->left!=NULL)
    {
        current=current->left;
    }
    return current;
}

struct node *delete(struct node *root,int key)
{
    if(root==NULL)
    {
        return root;
    }
    if(key<root->info)
    {
        root->left=delete(root->left,key);
    }
    else if(key>root->info)
    {
        root->right=delete(root->right,key);
    }
    else
    {
        if(root->left==NULL)
        {
            struct node *temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL)
        {
            struct node *temp=root->left;
            free(root);
            return temp;
        }
        struct node *temp=minvaluenode(root->right);
        root->info=temp->info;
        root->right=delete(root->right,temp->info);
    }
    return root;
}


void iot(struct node *root)
{
    if(root!=NULL)
    {
        iot(root->left);
        printf("%d ",root->info);
        iot(root->right);      
    }
}

void prot(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->info);
        prot(root->left);       
        prot(root->right);       
    }
}

void pot(struct node *root)
{
    if(root!=NULL)
    {
        pot(root->left);
        pot(root->right);
        printf("%d ",root->info);       
    }
}

void find()
{
    int data;
    struct node *temp=root;
    printf("\nEnter the element to find :");
    scanf("%d",&data);
    while(temp!=NULL)
    {
        if(data==temp->info)
        {
            printf("\nElement Found\n");
            return;
        }
        else if(data<temp->info)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    printf("Element Not Found\n");
}


int main()
{
    int key;
    int ch,data;
    while(1)
    {
        printf("\n1.Insert\n2.Delete\n3.InOrderTraversal\n4.PreOrderTraversal\n5.PostOrderTraversal\n6.Find\n7.Exit\n");
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter a value to insert :");
            scanf("%d",&data);
            root=insert(root,data);
            break;
            case 2:
            if(root==NULL)
            {
                printf("\nThe Tree IS Empty!!!");
            }
            else
            {
                printf("\nEnter the value to be deleted :");
                scanf("%d",&key);
                root=delete(root,key);
            }
            break;
            case 3:
            if(root==NULL)
            {
                printf("The Tree IS Empty!!!");
            }
            else
            {
                iot(root);
            }
            break;
            case 4:
            if(root==NULL)
            {
                printf("The Tree IS Empty!!!");
            }
            else
            {
                prot(root);
            }
            break;
            case 5:
            if(root==NULL)
            {
                printf("The Tree IS Empty!!!");
            }
            else
            {
                pot(root);
            }
            break;
            case 6:
            find();
            break;
            case 7:
            exit(0);
            default:
            printf("Invalid Choice!!!");
        }
    }
    return 0;
}