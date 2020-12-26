//Nearly sorted array using heap
//O(nlogk)

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> minh;
    int k;
    vector<int> res;
    cin>>k;
    int arr[] = {6,5,3,2,8,10,9};
    int size = sizeof(arr)/sizeof(int);
    
    for(int i=0;i<size;i++)
    {
        minh.push(arr[i]);
        if(minh.size()>k)
        {
            res.push_back(minh.top());
            minh.pop();
        }
    }
    
    while(minh.size()!=0)
    {
        res.push_back(minh.top());
        minh.pop();
    }
    
    for(auto it:res)
        cout<<it<<" ";
        
    return 0;
}



