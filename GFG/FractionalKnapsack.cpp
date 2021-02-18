#include<bits/stdc++.h>
using namespace std;

struct Item{
  int value;
  int weight;
};

bool compare(Item A, Item B)
{
    double r1 = (double)A.value/A.weight;
    double r2 = (double)B.value/B.weight;
    return r1>r2;
}

double FK(Item arr[], int w, int n)
{
    sort(arr, arr+n, compare);
    int curr_weight = 0;
    int final_value = 0;
    
    for(int i=0;i<n;i++)
    {
        if(curr_weight+arr[i].weight<=w)
        {
            curr_weight += arr[i].weight;
            final_value += arr[i].value;
        }
        
        else
        {
            int rem = w - curr_weight;
            final_value += arr[i].value * (double)rem/arr[i].weight;
            break;
        }
    }
    
    return final_value;
}


int main()
{
    Item arr[] = {{60,10},{100,20},{120,30}};
    cout<<FK(arr, 50, 3);
    return 0;
}