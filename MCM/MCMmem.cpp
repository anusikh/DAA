#include<iostream>
#include<climits>
#include<cstring>
using namespace std;

int static t[1001][1001];

int MCM(int arr[], int i, int j)
{
	if(i>=j)
		return 0;

	if(t[i][j]!=-1)
		return t[i][j];

	int min = INT_MAX;
	for(int k=i;k<j;k++)
	{
		int temp = MCM(arr,i,k)+MCM(arr,k+1,j)+(arr[i-1]*arr[k]*arr[j]);

		if(temp<min)
			min = temp;
	}
	t[i][j] = min;
	return min;
}

int main()
{
	int arr[]={1,2,3,4,3};
	memset(t,-1,sizeof(t));
	cout<<MCM(arr,1,4);
	return 0;
}