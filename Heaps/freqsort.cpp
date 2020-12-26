// Top K freqeunt numbers

#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> iPair;

int main()
{
    priority_queue<iPair> maxh;
    unordered_map<int,int> mp;
    int arr[] = {1,1,1,3,2,4};
    
    for(int i=0;i<7;i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        maxh.push(make_pair(it->second,it->first));
    }
    
    while(maxh.size()>0)
    {
        int freq = maxh.top().first;
        int de = maxh.top().second;
        
        for(int i=1;i<=freq;i++)
            cout<<de<<" ";
            
        maxh.pop();
    }

    return 0;
}
