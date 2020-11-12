#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int partition(int *A, int l, int h)
{
	int pivot = A[l];
	int i=l;
	int j=h;

	while(i<j)
	{
		do{
			i++;
		}while(A[i]<=pivot);

		do{
			j--;
		}while(A[j]>pivot);

		if(i<j)
			swap(&A[i], &A[j]);
	}

	swap(&A[l],&A[j]);
	return j;
}

void Quicksort(int *A, int l, int h)
{
	int j;
	if(l<h)
	{
		j = partition(A,l,h);
		Quicksort(A,l,j);
		Quicksort(A,j+1,h);
	}
}

int main()
{
	clock_t st, en;
    int i,j,n;
    double tc;
    printf("INPUT\tTotalCPUTime\n");
    for(n=5000;n<=50000;n=n+5000)
    {
        int *arr = (int *)malloc(sizeof(int)*n);
        
        for(i=0;i<n;i++)
        {
            arr[i] = rand()%101;
        }

        st = clock();
        Quicksort(arr,arr[0],arr[n-1]);
        en = clock();

        tc = (double)(en-st)/CLOCKS_PER_SEC;
        printf("\n %d\t%f \n",n,tc);
    }

    return 0;
}

