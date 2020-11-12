#include<iostream>
#include<string.h>
using namespace std;

string SCS(string X, string Y, int m, int n)
{
	int t[m][n];
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
		for(int j=0;j<n+1;j++)
		{
			if(X[i-1]==Y[j-1])
				t[i][j] =  1+t[i-1][j-1];
			else
				t[i][j] = std::max(t[i][j-1],t[i-1][j]);
		}
	}

	string s="";

	int i=m, j=n;
	while(i>0 && j>0)
	{
		if(X[i-1]==Y[j-1])
		{
			s.push_back(X[i]);
			i--;j--;
		}
		else
		{
			if(t[i][j-1]>t[i-1][j])
			{
				s.push_back(Y[j-1]);
				j--;
			}
			else
			{
				s.push_back(X[i-1]);
				i--;
			}
		}
	}

	while(i>0)
	{
		s.push_back(X[i-1]);
		i--;
	}

	while(j>0)
	{
		s.push_back(Y[j-1]);
		j--;
	}


	return s;
}

int main()
{
	string X = "abcd";
	string Y = "bcde";
	int m = X.length();
	int n = Y.length();
	cout<<SCS(X,Y,m,n);
	return 0;
}