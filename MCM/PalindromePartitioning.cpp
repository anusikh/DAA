#include<iostream>
#include<cstring>
#include<climits>
using namespace std;

bool isPalindrome(char *arr,int i ,int j)
{
	while(i<j)
	{
		if(arr[i]==arr[j])
			return false;
		j--;i++;
	}
	return true;
}

int PP(char *arr, int i, int j)
{
	if(i>=j)
		return 0;
	if(isPalindrome(arr,i,j))
		return 0;

	int min = INT_MAX;
	for(int k=i;k<j;k++)
	{
		int temp = PP(arr,i,k)+PP(arr,k+1,j)+1;
		if(temp<min)
			min=temp;
	}
	return min;
}

int main()
{
	char arr[]="geek";
	cout<<PP(arr,1,4);
	return 0;
}