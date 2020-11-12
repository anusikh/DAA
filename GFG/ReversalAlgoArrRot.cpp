//https://www.youtube.com/watch?v=QOpU9-l5T7Y&feature=youtu.be

#include<bits/stdc++.h>
using namespace std;

void RevArray(int arr[], int start, int end)
{
	while(start<end)
	{
		int temp = arr[start];
		arr[start] = arr[end];
		arr[end] = temp;
		start++;
		end--;
	}
}

void Rotate(int arr[], int d,int n)
{
	if(d==0)
		return;

	d = d%n;

	RevArray(arr, 0, d-1);
	RevArray(arr, d, n-1);
	RevArray(arr, 0, n-1);
}

void print(int array[], int n)
{
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
}

int main()
{
	int arr[] = {1,2,3,4,5,6,7};
	int n = sizeof(arr)/sizeof(arr[0]);
	int d = 2;

	Rotate(arr, d, n);
	print(arr, n);
	return 0;
} 