//Split the array and add the first part to the end
//Take an array double the size and then store the elements twice in that array.
//Then print values from the 'ROTATION point' till the length of array.

#include<bits/stdc++.h>
using namespace std;

void SplitArr(int arr[], int n, int d)
{
	int tmp[n*2] = {0};

	for(int i=0;i<n;i++)
	{
		tmp[i] = arr[i];
		tmp[i+n] = arr[i];
	}

	for(int i = d; i<(d+n); i++)
	{
		arr[i - d] = tmp[i];
	}
}


int main()  
{ 
    int arr[] = { 12, 10, 5, 6, 52, 36 }; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int d = 2; 
  
    SplitArr(arr, n, d); 
  
    for (int i = 0; i < n; ++i) 
        printf("%d ", arr[i]); 
  
    return 0; 
} 