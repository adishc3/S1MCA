#include<stdio.h>
#include<stdlib.h>
void display(int set)
{
    printf("$");
    for(int i=0;i<32;i++){
        if(set&(1<<i)){
            printf("%d",i);
        }
    }
    printf("}\n");
}

int main()
{
    int A=0,B=0,ch,n,x,result;
    while(1)
    {
        printf("1.2.3.4.5.6");
        printf("Enter ch");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            A=0;
            printf("Size of set a");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                scanf("%d",&x);
                (A|=1<<x);
            }
            break;
            case 2:
            B=0;
            printf("Size of set b");
            scanf("%d",&n);
            for(int i=0;i<n;i++)
            {
                scanf("%d",&x);
                (B|=1<<x);
            }
            break;
            case 3:
            result=A|B;
            printf("union");
            display(result);
            break;
            case 4:
            result=A&B;
            printf("Intersection");
            display(result);
            break;
            case 5:
            result=A&~B;
            printf("Difference");
            display(result);
            break;
            case 6:
            exit(0);
            default:
            printf("Invalid");
        }
    }
    return 0;
}