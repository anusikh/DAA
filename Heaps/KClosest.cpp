//K Closest Numbers

#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int,int> iPair;

int main()
{
    priority_queue<iPair> maxh;
    int k,x;
    cin>>k>>x;
    int arr[] = {5,6,7,8,9};
    
    for(int i=0;i<5;i++)
    {
        maxh.push(make_pair(abs(arr[i]-x), arr[i]));
        if(maxh.size()>k)
        {
            maxh.pop();
        }
    }
    
    //cout<<maxh.size();
    
    while(maxh.size()!=0)
    {
        cout<<maxh.top().second<<endl;
        maxh.pop();
    }
    
    return 0;
    
}