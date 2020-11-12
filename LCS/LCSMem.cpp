#include<iostream>
#include<cstring>
using namespace std;

int static t[1001][1001];

int LCS(char *X, char *Y, int m, int n)
{
	if(m==0||n==0)
		return 0;

	if(t[m][n]!=-1)
		return t[m][n];

	if(X[m-1]==Y[n-1])
	{
		t[m][n] = 1+LCS(X,Y,m-1,n-1);
		return t[m][n];
	}
	else
	{
		t[m][n] = std::max(LCS(X,Y,m-1,n), LCS(X,Y,m,n-1));
		return t[m][n];
	}
}

int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	int m = strlen(X);
	int n = strlen(Y);
	memset(t, -1, sizeof(t));
	
	cout<<"Result: "<<LCS(X,Y,m,n);
	
	return 0;
}