#include<iostream>
#include<string.h>
using namespace std;

int LCS(char *X, char *Y, int m, int n)
{
	if(m==0||n==0)
		return 0;
	if(X[m-1]==Y[n-1])
		return 1+LCS(X,Y,m-1,n-1);
	else
		return std::max(LCS(X,Y,m-1,n), LCS(X,Y,m,n-1));
}

int main()
{
	char X[] = "AGGTAB";
	char Y[] = "GXTXAYB";
	int m = strlen(X);
	int n = strlen(Y);

	cout<<"Output: "<<LCS(X,Y,m,n);
	return 0;
}