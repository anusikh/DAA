#include<iostream>
using namespace std;

int coin_chain(int coin[], int sum, int n)
{
	int t[n+1][sum+1];
	for(int i=0;i<n+1;i++)
	{
		for(int j=0;j<sum+1;j++)
		{
			if(i==0)
				t[i][j] = 0;
			if(j==0)
				t[i][j] = 1;
		}
	}

	for(int i=1;i<n+1;i++)
	{
		for(int j=1;j<sum+1;j++)
		{
			if(coin[i-1]<=j)
				t[i][j] = t[i][j-coin[i-1]]+t[i-1][j];
			else
				t[i][j] = t[i-1][j];
		}
	}

	return t[n][sum];
}

int main()
{
	int coin[]={1,2,3};
	int sum=5;
	int n=3;

	cout<<coin_chain(coin,sum,n);

	return 0;

}