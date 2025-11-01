#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 5

int cq[MAX_SIZE];
int front=-1;
int rear=-1;

void enq(int item);
void dq();
void inc();
void disp();
void count();

int main()
{
    int ch,item;
    while(1)
    {
        printf("--------Circular queue--------\n");
        printf("1.insert\n2.delete\n3.display\n4.count\n5.increase value by 10\n6.exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the element to insert :");
            scanf("%d",&item);
            enq(item);
            break;
            case 2:
            dq();
            break;
            case 3:
            disp();
            break;
            case 4:
            count();
            break;
            case 5:
            inc();
            break;
            case 6:
            exit(0);
            default:
            printf("Wrong choice!");
        }
    }
    return 0;
}

void enq(int item)
{
    if((front==0 && rear==MAX_SIZE-1)||(rear==(front-1)%(MAX_SIZE)))
    {
        printf("OVERFLOW\n");
    }
    else if(front==-1)
    {
        front=rear=0;
        cq[rear]=item;
        printf("THE ELEMENT IS INSERTED\n");
    }
    else if(rear==MAX_SIZE-1 && front!=0)
    {
        rear=0;
        cq[rear]=item;
        printf("THE ELEMENT IS INSERTED\n");
    }
    else
    {
        rear++;
        cq[rear]=item;
        printf("THE ELEMENT IS INSERTED\n");
    }
}

void dq()
{
    if(front==-1)
    {
        printf("UNDERFLOW\n");
    }
    else if(front==rear)
    {
        front=-1;
        rear=-1;
        printf("THE ELEMENT IS DELETED\n");
    }
    else if(front==MAX_SIZE-1)
    {
        front=0;
        printf("THE ELEMENT IS DELETED\n");
    }
    else
    {
        front++;
        printf("THE ELEMENT IS DELETED\n");
    }
}

void inc()
{
    if(front==-1)
    {
        printf("UNDERFLOW!\n");
    }
    else if(rear>=front)
    {
        for(int i=front;i<=rear;i++)
        {
            cq[i]=cq[i]+10;
            printf("%d ",cq[i]);
        }
    }
    else
    {
        for(int i=front;i<MAX_SIZE;i++)
        {
             cq[i]=cq[i]+10;
            printf("%d ",cq[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            cq[i]=cq[i]+10;
            printf("%d ",cq[i]);
        }
    }
}

void disp()
{
    if(front==-1)
    {
        printf("UNDERFLOW!\n");
    }
    else if(rear>=front)
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",cq[i]);
        }
    }
    else
    {
        for(int i=front;i<MAX_SIZE;i++)
        {
            printf("%d ",cq[i]);
        }
        for(int i=0;i<=rear;i++)
        {
            printf("%d ",cq[i]);
        }
    }
}

void count()
{
    int counnt=0;
    if(front==-1)
    {
        printf("underflow the list is emptyyy!");
    }
    else if(rear>=front)
    {
        counnt=rear-front+1;
        printf("the number of elements is %d",counnt);
    }
    else
    {
        counnt=(MAX_SIZE-1)+(rear+1);
        printf("The number of elements is %d",counnt);
    }
}