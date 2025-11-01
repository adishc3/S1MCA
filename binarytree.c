#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createnode(int value)
{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("mem alloc failed");
        exit(1);
    }
    newnode->data=value;
    newnode->left=NULL;
    newnode->right=NULL;
    return newnode;
}
struct node *ins(struct node *root,int value)
{
    struct node *newnode=createnode(value);
    if(root==NULL)
    {
        return newnode;
    }
    struct node *q[100];
    int fr=0,rr=0;
    q[rr++]=root;
    while(fr<rr)
    {
        struct node *temp=q[fr++];
        if(temp->left==NULL)
        {
            temp->left=newnode;
            return root;
        }
        else
        {
            q[rr++]=temp->left;
        }
         if(temp->right==NULL)
        {
            temp->right=newnode;
            return root;
        }
        else
        {
            q[rr++]=temp->right;
        }
    }
    return root;
}

struct node *deepest(struct node *root)
{
    if(root==NULL)
    {
        return NULL;
    }
    struct node *q[100];
    int fr=0,rr=0;
    q[rr++]=root;
    struct node *temp=NULL;
    while(fr<rr)
    {
        temp=q[fr++];
        if(temp->left)
        {
            q[rr++]=temp->left;
        }
        if(temp->right)
        {
            q[rr++]=temp->left;
        }
    }
    return temp;
}

void dltdeepest(struct node* root,struct node *d_node)
{
    struct node *q[100];
    int fr=0,rr=0;
    q[rr++]=root;
    while(fr<rr)
    {
        struct node *temp=q[fr++];

    if(temp->left)
    {
        if(temp->left==d_node)
        {
            free(temp->left);
            temp->left=NULL;
            return;
        }
        else
        {
            q[rr++]=temp->left;
        }
    }
    if(temp->right)
    {
        if(temp->right==d_node)
        {
            free(temp->right);
            temp->right=NULL;
            return;
        }
        else
        {
            q[rr++]=temp->right;
        }
    }
    }
}

struct node *dlt(struct node *root,int key)
{
    if(root==NULL)
    {
        return NULL;
    }
    if(root->left==NULL&&root->right==NULL)
    {
        if(root->data==key)
        {
            free(root);
            return NULL;
        }
        else
        {
            return root;
        }
    }
    struct node *key_node=NULL;
    struct node *q[100];
    int fr=0,rr=0;
    q[rr++]=root;
    struct node *temp=NULL;
    while(fr<rr)
    {
        temp=q[fr++];
        if(temp->data==key)
        {
            key_node=temp;
        }    
        if(temp->left)
        {
            q[rr++]=temp->left;
        }
        if(temp->right)
        {
            q[rr++]=temp->right;
        }
        
    }
    if(key_node!=NULL)
        {
            struct node *deepest=temp;
            key_node->data=deepest->data;
            dltdeepest(root,deepest);
        }
    return root;
}

void iot(struct node *root)
{
    if(root!=NULL)
    {
        iot(root->left);
        printf("%d ",root->data);
        iot(root->right);      
    }
}

void prot(struct node *root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
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
        printf("%d ",root->data);       
    }
}


int main()
{
    struct node *root=NULL;
    int ch,value;
    while(1)
    {
        printf("\n1.insert\n2.Delete\n3.InOrderTraversal\n4.PreOrderTraversal\n5.PostOrderTraversal\n6.exit\n");
        printf("Enter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("\nEnter a value to insert");
            scanf("%d",&value);
            root=ins(root,value);
            break;
            case 2:
            if(root==NULL)
            {
                printf("\nthe tree is empty");
            }
            else
            {
                printf("\nEnter the value to be deleted :");
                scanf("%d",&value);
                root=dlt(root,value);
            }
            break;
            case 3:
            if(root==NULL)
            {
                printf("tree is empty");
            }
            else
            {
                iot(root);
            }
            break;
            case 4:
            if(root==NULL)
            {
                printf("tree is empty");
            }
            else
            {
                prot(root);
            }
            break;
            case 5:
            if(root==NULL)
            {
                printf("tree is empty");
            }
            else
            {
                pot(root);
            }
            break;
            case 6:
            exit(0);
            default:
            printf("Invalid choice");
        }
    }
    return 0;
}