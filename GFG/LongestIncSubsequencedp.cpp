#include<iostream>
using namespace std;


int max_element(int arr[], int n)
{
    int max = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i]>max)
            max = arr[i];
    }
    
    return max;
}


void LongestIncreasingSubseqeunce(int arr[], int n)
{
    int lis[n] = {1};
    
    for(int i=1;i<n;i++)
    {
        for(int j= 0;j<i;j++)
        {
            if(arr[i]>arr[j] && lis[i]<=lis[j])
            {
                lis[i] = lis[j]+1;
            }
        }
    }
    
    cout<<max_element(lis, n);
}


int main()
{
    int arr[] = {10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(int);
    LongestIncreasingSubseqeunce(arr, n);
    return 0;
}
