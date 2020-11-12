//Selsort and Bubble sort
#include<stdio.h>
#include<time.h>

void swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int n)
{
	//int flag =0;
	int i,j;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-i-1;j++)
		{
			if(arr[j]>arr[j+1])
				{
					swap(&arr[j], &arr[j+1]);
					//flag =1;
				}
		}
		//if(flag==0)
			//break;
	}
}

void sel_sort(int arr[], int n)
{
	int i,j;
	for(i=0;i<n;i++)
	{
		int min = i;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[min])
				min = j;
		}
		swap(&arr[i],&arr[min]);
	}
}

int main()
{
	int arr[5] = {1,5,4,3,2};
	int n=5,i;
	time_t st,en;
	st = clock();
	sel_sort(arr,n);
	//bubble_sort(arr,n);
	en = clock();

	double tc = ((double)(st-en))/CLOCKS_PER_SEC;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);

	printf("TC:%d ", tc);

	return 0;
}