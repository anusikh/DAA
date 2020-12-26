// K closest points to origin

#include<iostream>
#include<queue>
#include<unordered_map>
#include<vector>
using namespace std;

typedef pair<int,pair<int,int>> iPair;

int main()
{
    int arr[4][2] = {{1,3},{-2,2},{5,8},{0,1}};
    priority_queue<iPair> maxh;
    
    int k;
    cin>>k;
    
    for(int i=0;i<4;i++)
    {
        maxh.push(make_pair((arr[i][0]*arr[i][0]+arr[i][1]*arr[i][1]),make_pair(arr[i][0], arr[i][1])));
        while(maxh.size()>k)
        {
            maxh.pop();
        }
    }

    while(maxh.size()>0)
    {
        pair<int,int> p = maxh.top().second;
        cout<<p.first<< " "<<p.second<<" ";
        maxh.pop();
    }
    
    return 0;
}