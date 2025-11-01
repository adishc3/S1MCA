#include<stdio.h>
#include<stdlib.h>
int parent[100],rank[100];
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

void main()
{
    int cost[100][100],t[100][2],heap[100][3],i,j,k=0,l,m,n,u,v,mincost=0,min=100,t1,t2,t3;
    printf("Enter the Number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the cost of edges.... if edge doesn't exist then input 100:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("\ncost[%d][%d]",i,j);
            scanf("%d",&cost[i][j]);
            if(cost[i][j]<100)
            {
                k++;
                heap[k][1]=i;
                heap[k][2]=j;
                heap[k][3]=cost[i][j];
            }
        }
    }
    
    for(i=1;i<=n;i++)
    {
        parent[i]=i;
    }

    m=k;
    for(i=1;i<=m;i++)
    {
        for(j=i+1;j<=m;j++)
        {
            if(heap[i][3]>heap[j][3])
            {
                t1=heap[i][1];
                heap[i][1]=heap[j][1];
                heap[j][1]=t1;

                t2=heap[i][2];
                heap[i][2]=heap[j][2];
                heap[j][2]=t2;

                t3=heap[i][3];
                heap[i][3]=heap[j][3];
                heap[j][3]=t3;
            }
        }
    }

    i=0;
    for(j=1;j<=m && i<n;j++)
    {
        u=find(heap[j][1]);
        v=find(heap[j][2]);
        if(u!=v)
        {
            i++;
            t[i][1]=heap[j][1];
            t[i][2]=heap[j][2];
            mincost=mincost+heap[j][3];
            unionset(heap[j][1],heap[j][2]);
        }
    }
    printf("\nSpanning Treeeeeee!!");
    for(i=1;i<n;i++)
    {
        printf("\n(%d %d)",t[i][1],t[i][2]);
    }
    printf("\nMincost : %d",mincost);
}