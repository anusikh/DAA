//Move all zeros present in an array to the end

#include<bits/stdc++.h>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

void func(int arr[], int n)
{
	for(int i=0;i<n;i++)
	{
		int j=0;
		if(arr[i]!=0)
		{
			swap(arr, i, j);
			j++;
		}
	}
}

int main()
{
	int arr[] = {6, 0, 8, 2, 3, 0, 4, 0, 1};
	int n = sizeof(arr)/sizeof(int);
	func(arr,n);
	for(int i=0;i<n;i++)
		cout<<arr[i]<<" ";
}