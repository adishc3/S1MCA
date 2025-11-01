#include<stdio.h>
#include<stdlib.h>
void main()
{
    int near[20],cost[20][20],t[20][2],n,mincost=0,i,j,k,l,m,min;
    printf("Enter the number of vertex: ");
    scanf("%d",&n);
    printf("\nEnter the cost of edges ..... if no edge exist then enter 100:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            printf("cost[%d][%d]",i,j);
            scanf("%d",&cost[i][j]);

        }
    }
    min=100;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
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
        if(cost[i][k]>cost[i][l])
        {
            near[i]=l;
        }
        else
        {
            near[i]=k;
        }

    }
    near[k]=near[l]=0;
    for(i=2;i<n;i++)
    {
        min=100;
        for(j=1;j<=n;j++)
        {
            if(near[j]!=0 && cost[j][near[j]]<min)
            {
                min=cost[j][near[j]];
                m=j;
            }
        }
        t[i][1]=m;
        t[i][2]=near[m];
        mincost=mincost+cost[m][near[m]];
        near[m]=0;
        for(k=1;k<=n;k++)
        {
            if(near[k]!=0 && cost[k][near[k]]>cost[k][m])
            {
                near[k]=m;
            }
        }
    }
    printf("\nSpanning Treeeeeee!!");
    for(i=1;i<n;i++)
    {
        printf("\n(%d %d)",t[i][1],t[i][2]);
    }
    printf("\nMincost : %d",mincost);
}