//Heapsort

#include<iostream>
using namespace std;

void heapify(int A[], int i, int n)
{
    int largest = i;
    int l = (2*i)+ 1;
    int r = (2*i)+ 2;
    
    if(l<n && A[l]>A[largest])
        largest =l;
    if(r<n && A[r]>A[largest])
        largest = r;
        
    if(largest!=i)
    {
        swap(A[i],A[largest]);
        heapify(A,largest,n);
    }
}

void heapsort(int A[], int n)
{
    for(int i=(n/2)-1;i>=0;i--)
    {
        heapify(A,i,n);
    }
    
    for(int i=n-1;i>0;i--)
    {
        swap(A[0],A[i]);
        heapify(A,0,i);
    }
}

int main()
{
    int A[] = {9,2,3,4,7};
    int n = sizeof(A)/sizeof(A[0]);
    
    heapsort(A,n);
    
    for(int i=0;i<n;i++)
        cout<<A[i]<<" ";
        
    return 0;
}