#include<bits/stdc++.h>
using namespace std;

long minTime(vector<long> machines, long goal)
{
    sort(machines.begin(), machines.end());
    int n = machines.size();

    long low = 1, high = 1e18;
    long mid = 0;
    long ans = 0;

    while(low<=high)
    {
        mid = (low+high)/2;
        long prod = 0;
        for(int i=0; i<n; i++)
        {
            prod+=mid/machines[i];
            if(prod>=goal)
                break;
        }

        if(prod>=goal)
        {
            high = mid - 1;
            ans = mid;
        }
        else
        {
            low = mid+1;
        }
    }

    return ans;
}

int main()
{
    int n;
    long goal;
    cin>>n>>goal;

    vector<long> machines;
    for(int i=0;i<n;i++)
    {
        long a;
        cin>>a;
        machines.push_back(a);
    }

    cout<<minTime(machines,goal);

    return 0;
}