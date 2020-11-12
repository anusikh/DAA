#include<iostream>
using namespace std;

int main()
{
  int n,m;
  cin>>m>>n;
  int *arr = new int[n+1];

  for(int i=0;i<n+1;i++)
  {
    arr[i]=0;
  }

  for(int i=0;i<m;i++)
  {
    int p,q,r;
    cin>>p>>q>>r;

    arr[p] = arr[p]+r;
    if(q+1<=n)
      arr[q] = arr[q]-r;
  }

  int max=0, sum=0;

  for(int i=0;i<n+1;i++)
  {
    sum = sum+arr[i];
    if(sum>max)
    {
      max = sum;
    }
  }


  cout<<max<<endl;

}

