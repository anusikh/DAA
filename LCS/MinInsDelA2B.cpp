#include<iostream>
#include<cstring>
using namespace std;

int LCS(char *X, char *Y,int m, int n)
{
	int t[m][n];
	for(int i=0;i<m+1;i++)
	{
		for(int j=0;j<n+1;j++)
		{
			if(i==0||j==0)
				t[i][j] = 0;
		}
	}

	for(int i=1;i<m+1;i++)
	{
		for(int j=1;j<n+1;j++)
		{
			if(X[i-1]==Y[j-1])
				t[i][j] = 1+t[i-1][j-1];
			else
				t[i][j] = std::max(t[i-1][j], t[i][j-1]);
		}
	}

	return t[m][n];
}

int main()
{
	char X[] = "heap";
	char Y[] = "pea";
	int m = strlen(X);
	int n = strlen(Y);
	
	cout<<"Min No. of Insertions: "<<n-LCS(X,Y,m,n);
	cout<<"Min No. of Deletions: "<<m-LCS(X,Y,m,n);
	return 0;

}