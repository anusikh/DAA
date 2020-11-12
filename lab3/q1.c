#include<stdio.h>

void Prime1(int num)
{
    int i, flag=0; int count=0;
    count++;
    for(i=2;i<=num/2;i++)
    {
        count++;
        if(num%i==0){
            flag=1;
            break;
        }
    }

    if(num==1){
        count++;
        printf("Neither Prime Or Composite. \n");
    }
    else{
        if(flag==0)
           {
            count++;
            printf("Prime \n");
           }
        else
        {
            count++;
            printf("Not Prime \n");
        }
    }

    printf("Freq:%d \n", count);
}

void Prime2(int num) 
{  
    int count=0;
    int i,c=0;
    for(i=1;i<=num;i++)
    {
        count++;
        if(num%i==0)
            c++;
    }

    if(c==2){
        count++;
        printf("Prime2.\n");
    }
    else{
        count++;
        printf("Not Prime2.\n");
    }

    printf("Freq:%d",count);
}

int main()
{
    int num;
    printf("Enter the Value PLs:");
    scanf("%d", &num);
    Prime1(num);
    Prime2(num);
    return 0;
}