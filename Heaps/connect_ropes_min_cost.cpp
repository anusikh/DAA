// connect ropes to minimize cost
#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int main()
{
    int arr[] = {1,2,3,4,5};
    priority_queue<int, vector<int>, greater<int>> minh;
    int cost=0;
    
    for(int i = 0;i<5;i++)
    {
        minh.push(arr[i]);
    }
    
    while(minh.size()>=2)
    {
        int first = minh.top();
        minh.pop();
        int second = minh.top();
        minh.pop();
        
        cost = cost + first + second;
        minh.push(first+second);
    }
    
    cout<<cost;
    return 0;
}