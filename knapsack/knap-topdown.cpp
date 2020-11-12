#include<bits/stdc++.h>
using namespace std;

int knapsack(int wt[], int val[], int w,int n)
{
    int t[n+1][w+1];
    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(i==0||j==0)
                t[i][j] = 0;
            else if(wt[i-1]<=j)
                t[i][j] = std::max(val[i-1]+t[i-1][j-wt[i-1]], t[i-1][j]);
            else if(wt[i-1]>j)
                t[i][j] = t[i-1][j];
        }
    }
    return t[n][w];
}

int main()
{
    int wt[] = {1,2,3,4};
    int val[] = {2,3,4,5};
    int w=7;
    int n=4;

    int res = knapsack(wt,val,w,n);
    cout<<res<<endl;

    return 0;
}