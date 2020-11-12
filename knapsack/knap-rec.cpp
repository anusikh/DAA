#include<iostream>
using namespace std;

int knapsack(int wt[], int val[], int w, int n)
{
    if(n==0||w==0)
    {
        return 0;
    }
    if(wt[n-1]<=w)
    {
        return std::max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
    }
    else if(wt[n-1]>w)
    {
        return knapsack(wt, val, w, n-1);
    }
}

int main()
{
    int wt[]={1,2,3,4};
    int val[]={2,3,4,5};
    int w=7;
    int n=4;

    int res = knapsack(wt,val,w,n);
    cout<<res;

    return 0;
}