#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int LinearSearch(int *arr, int key)
{
    int i;
    for(i=0; i<1000000; i++)
        if(arr[i]==key)
            printf("The Index of Element is: %d \n", i);
    return -1;
}

int main()
{
    clock_t st, en;
    int *arr = (int *)malloc(sizeof(int)*1000000);
    int i;
    for(i = 0; i<1000000; i++)
        arr[i] = rand();

    st = clock();
    LinearSearch(arr, arr[0]);
    en = clock();
    double time_taken = ((double)(st-en));

    printf("Time Taken by LinearSearch() is: %f \n", time_taken);

    return 0;
}