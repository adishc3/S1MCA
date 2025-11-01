#include<stdio.h>
#include<stdlib.h>
int u[15],a[15],b[15],n;

void insert(int s[]){
    int i,num,j,flag,m,k;
    printf("\nenter the size of the set:");
    scanf("%d",&m);
    printf("\n");
    printf("Enter the elements:{");
    for(i=0;i<m;i++)
    {
        scanf("%d",&num);
        flag=0;
        for(j=0;j<n;j++){
            if(u[j]==num && s[j]==0)
            {
                flag=1;
                k=j;
            }

        }
        if(flag==1){
            s[k]=1;
        }
        else
        {
            printf("\n invalid entry!!!");
            i--;
        }
    }
    printf("}\n");
}

void creation()
{
    int i,num,j,flag;
    printf("\nenter the size of the set:");
    scanf("%d",&n);
    printf("\n");
    printf("Enter the elements:{");
    for(i=0;i<n;i++)
    {
        scanf("%d",&num);
        flag=0;
        for(j=0;j<i;j++){
            if(u[j]==num)
            {
                flag=1;
            }

        }
        if(flag==0){
            u[i]=num;
            a[i]=b[i]=0;
        }
    }
    printf("}\n");
}

void un(){
    int i;
    printf("\n{");
    for(i=0;i<n;i++)
    {
        if(a[i]||b[i])
        {
            printf("%d",u[i]);
        }
    }
    printf("}\n");
}

void iin(){
    int i;
    printf("\n{");
    for(i=0;i<n;i++)
    {
        if(a[i]&&b[i])
        {
            printf("%d",u[i]);
        }
    }
    printf("}\n");
}

void diff(int s1[],int s2[]){
    int i;
    printf("\n{");
    for(i=0;i<n;i++)
    {
        if(s1[i]==1&&s2[i]==0)
        {
            printf("%d",u[i]);
        }
    }
    printf("}\n");
}

void disp(int s[]){
    int i;
    printf("\n{");
    for(i=0;i<n;i++)
    {
        printf("%d ",s[i]);
    }
    printf("}\n");
}

void main()
{
    printf("Enter the universal set:");
    creation();
    printf("Enter set A:");
    insert(a);
    disp(a);
    printf("Enter set B:");
    insert(b);
    disp(b);
    printf("union");
    un();
    printf("intersection");
    iin();
    printf("difference");
    diff(a,b);
}