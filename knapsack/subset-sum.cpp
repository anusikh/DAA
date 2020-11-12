#include<bits/stdc++.h>
using namespace std;

bool Subset_Sum(int arr[], int sum, int n)
{
    int t[n+1][sum+1];

    for(int i=0;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(i==0)
                t[i][j]=false;
            else if(j==0)
                t[i][j]=true;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
            {
                t[i][j]=t[i-1][j]||t[i-1][j-arr[i-1]];
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
    int arr[]={2,3,7,8,10};
    int sum=10;
    int n=5;

    if(Subset_Sum(arr, sum, n)==true)
        printf("Found!!!\n");
    else if(Subset_Sum(arr, sum, n)==false)
        printf("Not Found!!!\n");
    
    return 0;
}
