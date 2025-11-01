#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

void insbeg(struct node **head_ref,struct node **tail_ref,int data);
void insend(struct node **head_ref,struct node **tail_ref,int data);
void delbeg(struct node **head_ref,struct node **tail_ref);
void delend(struct node **head_ref,struct node **tail_ref);
void disbeg(struct node *head);
void disend(struct node *head,struct node *tail);
int count(struct node *head);
 
 int main()
 {
    struct node *head=NULL;
    struct node *tail=NULL;
    int val,ch;
    while(1)
    {
        printf("\n------Doubly Linked List------\n");
        printf("1.Insert at beginning\n2.insert at end\n3.delete from beginning\n4.delete from end\n5.display from beginning\n6.display from end\n7.count the number of elements\n8.exit");
        printf("\nEnter your choice :");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the data to be inserted :");
            scanf("%d",&val);
            insbeg(&head,&tail,val);
            break;
            case 2:
            printf("Enter the data to be inserted :");
            scanf("%d",&val);
            insend(&head,&tail,val);
            break;
            case 3:
            delbeg(&head,&tail);
            break;
            case 4:
            delend(&head,&tail);
            break;
            case 5:
            disbeg(head);
            break;
            case 6:
            disend(head,tail);
            break;
            case 7:
            printf("the number of elements is %d",count(head));
            printf("\n");
            printf("\n");
            break;
            case 8:
            exit(0);
            default:
            printf("invalid");
        }
    }
    return 0;
 }

 void insbeg(struct node **head_ref,struct node **tail_ref,int data)
 {
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("mem alloc failed");
    }
    newnode->data=data;
    newnode->prev=NULL;
    newnode->next=*head_ref;
    if(*head_ref==NULL)
    {
        *head_ref=newnode;
        *tail_ref=newnode;
    }
    else
    {
        (*head_ref)->prev=newnode;
        *head_ref=newnode;
    }
    printf("\ndata inserted\n");
    printf("\n");
    printf("\n");
 }

 void insend(struct node **head_ref,struct node **tail_ref,int data)
 {
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("mem alloc failed");
    }
    newnode->data=data;
    newnode->prev=*tail_ref;
    newnode->next=NULL;
    if(*tail_ref==NULL)
    {
        *head_ref=newnode;
        *tail_ref=newnode;
    }
    else
    {
        (*tail_ref)->next=newnode;
        *tail_ref=newnode;
    }
    printf("\ndata inserted\n");
    printf("\n");
    printf("\n");
 }

 void delbeg(struct node **head_ref,struct node **tail_ref)
 {
    if(*head_ref==NULL)
    {
        printf("The list is empty\n");
        printf("\n");
        printf("\n");
        return;
    }
    if(*head_ref==*tail_ref)
    {
        *head_ref=NULL;
        *tail_ref=NULL;
    }
    else
    {
        *head_ref=(*head_ref)->next;
        (*head_ref)->prev=NULL;
    }
    printf("data at beginning deleted\n");
    printf("\n");
    printf("\n");
 }

 void delend(struct node **head_ref,struct node **tail_ref)
 {
    if(*head_ref==NULL)
    {
        printf("The list is empty\n");
        printf("\n");
        printf("\n");
        return;
    }
    if(*head_ref==*tail_ref)
    {
        *head_ref=NULL;
        *tail_ref=NULL;
    }
    else
    {
        *tail_ref=(*tail_ref)->prev;
        (*tail_ref)->next=NULL;
    }

    printf("data at end deleted\n");
    printf("\n");
    printf("\n");
 }

 void disbeg(struct node *head)
 {
    if(head==NULL)
    {
        printf("The list is empty\n");
        printf("\n");
        printf("\n");
        return;
    }
    printf("The list (from beggining) : NULL<->");
    struct node *current=head;
    while(current!=NULL)
    {
        printf(" %d <->",current->data);
        current=current->next;
    }
    printf(" NULL");
    printf("\n");
    printf("\n");
 }

 void disend(struct node *head,struct node *tail)
 {
    if(head==NULL)
    {
        printf("The list is empty\n");
        printf("\n");
        printf("\n");
        return;
    }
    printf("The list (from end) : NULL<-> ");
    struct node *current=tail;
    while(current!=NULL)
    {
        printf(" %d <->",current->data);
        current=current->prev;
    }
    printf(" NULL\n");
    printf("\n");
    printf("\n");
 }

 int count(struct node *head)
 {
    int ct=0;
    if(head==NULL)
    {
        printf("List is empty\n");
        
        return ct;
    }
    else
    {
        struct node *current=head;
        while(current!=NULL)
           {
               current=current->next;
               ct++;
           }
       return ct;

    }
    
 }