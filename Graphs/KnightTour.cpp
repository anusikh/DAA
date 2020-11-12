#include<bits/stdc++.h>
#define n 8
using namespace std;


int is_safe(int x, int y, int sol[n][n])
{
	return (x>=0 && x<n && y>=0 && y<n && sol[x][y]==-1);
}

void print(int sol[n][n])
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<" "<<sol[i][j]<<" ";
		}
		cout<<"\n";
	}
}

int KTUtil(int x, int y, int mv, int sol[n][n], int dx[n], int dy[n])
{
	int k, nx, ny;
	if(mv == n*n)
		return 1;

	for(k=0;k<n;k++)
	{
		nx = x+dx[k];
		ny = y+dy[k];
		if(is_safe(nx,ny,sol))
		{
			sol[nx][ny]=mv;
			if(KTUtil(nx, ny, mv+1, sol, dx, dy)==1)
				return 1;
			else
				sol[nx][ny]=-1;
		}
	}
	return 0;
}

int KT()
{
	int sol[n][n];
	memset(sol, -1, sizeof(sol));

	int dx[n]={2, 1, -1, -2, -2, -1, 1, 2};
	int dy[n]={1, 2, 2, 1, -1, -2, -2, -1};
	sol[0][0]=0;

	if(KTUtil(0,0,1,sol,dx,dy)==0)
	{
		cout<<" No SOl";	
	}
	else
		print(sol);

	return 0;
}

int main()
{
	KT();
	return 0;
}