#include<iostream>
#include<string.h>
using namespace std;

int LCSubstring(char *X, char *Y, int m, int n)
{
	int t[m][n];
	int res = 0;

	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0||j==0)
				t[i][j]=0;
		}
	}

	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(X[i-1]==Y[j-1])
			{
				t[i][j] = 1+t[i-1][j-1];
				res = std::max(res, t[i][j]);

			}
			else
			{
				t[i][j] = 0;
			}
		}
	}

	return t[m][n];
}

int main()
{
	char X[] = "abcdef";
	char Y[] = "abdcefg";
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<"Result: "<<LCSubstring(X,Y,m,n);
	
	return 0;
}