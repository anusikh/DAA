//Selsort

#include<iostream>
using namespace std;

void Selsort(int A[], int n)
{
    int min=0;
    for(int i=0;i<n-1;i++)
    {
        min = i;
        for(int j=i+1;j<n;j++)
        {
            if(A[j]<A[min])
                min = j;
        }
        
        swap(A[min],A[i]);
    }
}

int main()
{
    int A[] = {9,2,3,4,7};
    int n = sizeof(A)/sizeof(A[0]);
    
    Selsort(A,n);
    
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
        
    return 0;
}