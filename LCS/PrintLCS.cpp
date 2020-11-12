#include<bits/stdc++.h>
#include<string.h>
using namespace std;


string LCS(char *X, char *Y, int m, int n)
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
		for(int j=1;j<n+1;j++)
		{
			if(X[i-1]=Y[j-1])
				t[i][j] = 1 + t[i-1][j-1];
			else
				t[i][j] = std::max(t[i-1][j], t[i][j-1]);
		}
	}


	string s="";
	int i=m, j=n;
	while(i>0 && j>0)
	{
		if(X[i-1]==Y[j-1])
		{
			s.push_back(X[i-1]);
			i--;j--;
		}
		else
		{
			if(t[i][j-1]>t[i-1][j])
				j--;
			else
				i--;
		}
	} 

	std::reverse(s.begin(), s.end());

	return s;
}


int main()
{	
	char X[] = "abcdef";
	char Y[] = "abcdefg";
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<LCS(X,Y,m,n);
	return 0;
}