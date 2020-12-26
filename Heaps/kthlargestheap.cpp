#include<queue>
#include<iostream>
using namespace std;

int main()
{
    priority_queue<int, vector<int>, greater<int>> minh;
    int k;
    cin>>k;
    vector<int> arr{7,10,4,3,20,15};
    for(int i=0;i<arr.size();i++)
    {
        minh.push(arr[i]);
        if(minh.size()>k)
        {
            minh.pop();
        }
    }
    
    while(minh.size()!=0)
    {
        cout<<minh.top()<<" ";
        minh.pop();
    }
    
    return 0;
}