#include<iostream>
#include<climits>
using namespace std;

int MCM(int arr[], int i, int j)
{
	if(i>=j)
		return 0;
	
	int min = INT_MAX;
	for(int k=i;k<j;k++)
	{		
		int temp = MCM(arr,i,k)+MCM(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);
		if(temp<min)
		min = temp;
	}
	return min;
}

int main()
{
	int arr[]={1,2,3,4,3};
	cout<<MCM(arr,1,4);
	return 0;
}