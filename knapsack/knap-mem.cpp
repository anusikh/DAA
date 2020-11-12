#include<iostream>
#include<cstring>
using namespace std;

//Here we declare a matrix t[n+1][w+1] such that all its elements are initially assigned to -1

static int t[5][8]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int knapsack(int wt[],int val[], int w, int n)
{
    //Base Condition
    if(n==0||w==0)
        return 0;
    
    if(t[n][w]!=-1)
        return t[n][w];
    
    if(wt[n-1]<=w)
    {
        t[n][w] = std::max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1), knapsack(wt,val,w,n-1));
        return t[n][w];
    }
    else if(wt[n-1]>w)
        t[n][w] = knapsack(wt,val,w,n-1);
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