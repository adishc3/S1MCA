#include<stdio.h>
#include<stdlib.h>
void main()
{
    int near[20],cost[20][20],t[20][2],n,mincost=0,i,j,k,l,m,min;
    printf("please enter the number of vertices!!!");
    scanf("%d",&n);
    printf("Now enter the cost of edges , if none enter 100");
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            printf("cost[%d][%d]",i,j);
            scanf("%d",&cost[i][j]);
        }
    }
    min=100;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(cost[i][j]<min)
            {
                min=cost[i][j];
                k=i;
                l=j;
            }
        }
    }
    t[1][1]=k;
    t[1][2]=l;
    mincost=cost[k][l];
    for(i=1;i<=n;i++)
    {
        if(cost[i][k]<cost[i][l])
        {
            near[i]=k;
        }
        else
        {
            near[i]=l;
        }
    }
    near[k]=near[l]=0;
    for(i=2;i<=n;i++)
    {
        
    }
}