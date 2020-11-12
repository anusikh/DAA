#include<iostream>
using namespace std;

int knapsack(int dist[], int profits[], int k, int n)
{
    if(n==0||k==0)
    {
        return 0;
    }
    if(dist[n-1]<=k)
    {
        return std::max(profits[n-1]+knapsack(dist,profits,k-dist[n-1],n-1), knapsack(dist,profits,k,n-1));
    }
    else if(dist[n-1]>k)
    {
        return knapsack(dist, profits, k, n-1);
    }
}

int main()
{
    int dist[]={0,2,4,5,6};
    int profits[]={0,10,20,40,80};
    int k=2;
    int n=5;

    int res = knapsack(dist,profits,k,n);
    cout<<res;

    return 0;
}