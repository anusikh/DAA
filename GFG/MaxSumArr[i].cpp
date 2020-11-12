//MAx Sum of i*arr[i] among all the possible rotations
//next_val = curr_val - (cum_sum - arr[i-1]) + arr[i-1] * (n-1);


#include<bits/stdc++.h>
using namespace std;

int MaxSum(int arr[], int n)
{
	int cum_sum = 0;
	//Find the Sum of all the elements in the array
	for(int i=0;i<n;i++)
	{
		cum_sum += arr[i];
	}

	//Find the Value for the first rotation
	int curr_val = 0;
	for(int i=0;i<n;i++)
	{
		curr_val += i*arr[i]; 
	}

	int res = curr_val;

	for(int i =1;i<n;i++)
	{
		int next_val = curr_val - (cum_sum - arr[i-1]) + arr[i-1]*(n-1);
		curr_val = next_val;
		res = max(res, next_val);
	}

	return res;
}

int main()
{
	int arr[] = {8, 3, 1, 2}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << MaxSum(arr, n) << endl; 
    return 0; 
}