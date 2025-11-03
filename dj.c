#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int parent[MAX],rank[MAX];
void makeset(int n)
{
    for(int i=1;i<=n;i++)
    {
        parent[i]=i;
        rank[i]=0;
    }
}

int find(int x){
    if(parent[x]!=x)
    {
        parent[x]=find(parent[x]);
    }
    return parent[x];
}

void unionset(int x,int y)
{
    int xroot=find(x);
    int yroot=find(y);
    if(xroot==yroot)
    {
        return;
    }
    if(rank[xroot]<rank[yroot])
    {
        parent[xroot]=yroot;
    }
    else if(rank[xroot]>rank[yroot])
    {
        parent[yroot]=xroot;
    }
    else
    {
        parent[yroot]=xroot;
        rank[xroot]++;
    }
}

int main()
{
    int n,ch,a,b;
    printf("Enter the no. of elements");
    scanf("%d",&n);
    makeset(n);
    while(1)
    {
        printf("1.union,2.find,3.exit\n");
        printf("Enter your choice");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter the elements to union\n");
            scanf("%d %d",&a,&b);
            unionset(a,b);
            printf("Union Finished\n");
            break;
            case 2:
            printf("Enter the element to find\n");
            scanf("%d",&a);
            printf("The element %d parent node is %d\n",a,find(a));
            break;
            case 3:
            exit(0);
            default:
            printf("please enter a valid option\n")
        }
    }
}
