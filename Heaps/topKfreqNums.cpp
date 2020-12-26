// Top K freqeunt numbers

#include<iostream>
#include<unordered_map>
#include<queue>
#include<vector>
using namespace std;

typedef pair<int,int> iPair;

int main()
{
    priority_queue<iPair, vector<iPair>, greater<iPair>> minh;
    unordered_map<int,int> mp;
    int arr[] = {1,1,1,3,2,2,4};
    int k;
    cin>>k;
    
    for(int i=0;i<7;i++)
    {
        mp[arr[i]]++;
    }
    
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        minh.push(make_pair(it->second,it->first));
        if(minh.size()>k)
        {
            minh.pop();
        }
    }
    
    while(minh.size()!=0)
    {
        cout<<minh.top().second<<" ";
        minh.pop();
    }

    return 0;
}
