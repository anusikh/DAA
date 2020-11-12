#include<iostream>
using namespace std;

int solve(string s, int i, int j, bool istrue)
{
	int ans;
	if(i>j)
		return false;

	if(i==0)
	{
		if(istrue==true)
		{
			s[i]=true;
			return s[i];
		}
		else
		{
			s[i]=false;
			return s[i];
		}
	}

	for(int k=i+1;k<j;k++)
	{
		int lt = solve(s,i,k-1,true);
		int lf = solve(s,i,k-1,false);
		int rt = solve(s,k+1,j,true);
		int rf = solve(s,k+1,j,false);

		if(s[k]=='&')
		{
			if(istrue=true)
				ans = ans+(lt*rt);
			else
				ans = ans+(lf*rt)+(lt*rf)+(lf*rf);
		}

		if(s[k]=='|')
		{
			if(istrue=true)
				ans = ans+(lt*rt)+(lf*rt)+(lt*rf);
			else
				ans = ans+(lf*rf);
		}

		if(s[k]=='&')
		{
			if(istrue=true)
				ans = ans+(lt*rf)+(lf*rt);
			else
				ans = ans+(lf*rf)+(lt*rt);
		}
	}

	return ans;

}
