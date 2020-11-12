#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void LinearS(int *A, int key){
    int i; int count=0;
    count++;
    for(i=0; i<=9; i++)
    {   
        count++;
        if(A[i]==key)
        {
            count++;
            printf("%d\n",i);
            printf("Freq:%d\n",count); 
        }
    }

      
}

int main()
{
    clock_t st,en;
    int *A = (int *)malloc(sizeof(int)*10);
    printf("Enter The elements:");
    int i;
    for(i=0;i<=8;i++)
        scanf("%d ", &A[i]);
    
    int j;

    for(i=0;i<=9;i++)
    {   
        st = clock();
        LinearS(A, A[i]);
        en = clock();

        double time_taken= ((double)(st-en));
        printf("Time Taken:%0.111f\n", time_taken);
        
    }
    return 0;
}


