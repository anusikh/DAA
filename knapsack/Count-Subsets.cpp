#include<bits/stdc++.h>
using namespace std;

int Count_Subset_Sum(int arr[], int sum, int n)
{
    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j]=0;
            else if(j==0)
                t[i][j]=1;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]=t[i-1][j]+t[i-1][j-arr[i-1]];
            }
            else if(arr[i-1]>j)
            {
                t[i][j]=t[i-1][j];
            }
        }
    }

    return t[n][sum];
}

int main()
{
    int arr[]={0,2,3,5,6,8,10}; // Always start with 0
    int sum=8;
    int n=sizeof(arr)/sizeof(int);

    cout<<Count_Subset_Sum(arr,sum,n)<<endl;
    return 0;
}