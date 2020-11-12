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
                t[i][j]=0;
            else if(j==0)
                t[i][j]=1;
        }
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<sum+1;j++)
        {
            if(arr[i-1]<=j)
                t[i][j] = t[i-1][j]||t[i-1][j-arr[i-1]];
            else if(arr[i-1]>j)
                t[i][j]=t[i-1][j];
        }
    }

    return t[n][sum];
}

bool Equal_Sum_Subset(int arr[],int n)
{
    int sum=0;
    for(int i=0; i<n;i++)
        sum+=arr[i];

    if(sum%2!=0)
        return false;
    else
        return Subset_Sum(arr, sum/2, n);
}

int main()
{
    int arr[]={1,5,11,5};
    int n=4;
    if(Equal_Sum_Subset(arr,n)==false)
        cout<<"Cannot Be Divided!!!"<<endl;
    else
        cout<<"Can Be Divided!!!"<<endl;

    return 0;
}