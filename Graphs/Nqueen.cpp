#include<bits/stdc++.h>
using namespace std;
#define N 4

//print the solution
void print_sol(int board[N][N])
{
	for(int i=0;i<N;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
}


bool is_safe(int board[N][N],int row, int col)
{
	int i, j;
	for( i=0;i<col;i++)
	{
		if(board[row][i]!=0)
			return false;
	}

	for(i=row,j=col; j>=0 && i>=0; i--, j--)
	{
		if(board[i][j]!=0)
			return false;
	}

	for(i=row,j=col; j>=0 && i<N; i++, j--)
	{
		if(board[i][j])
			return false;
	}
	return true;
}

bool nqutil(int board[N][N], int col)
{
	if(col>=N)
		return true;
	
	for(int i=0;i<N;i++)
	{
		if(is_safe(board, i, col))
		{
			board[i][col] = 1;
			if(nqutil(board, col+1))
				return true;

			board[i][col]=0;
		}

	}
	return false;
}

bool nq()
{
	int board[N][N] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

	if(nqutil(board, 0)==false){
		cout<<"No Solution";
		return false;
	}
	
	print_sol(board);
	return true;
}

int main()
{
	nq();
	return 0;
}