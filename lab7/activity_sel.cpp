#include<bits/stdc++.h>
using namespace std;

struct Act{
	int start;
	int finish;
};

bool comp(Act a1, Act a2)
{
	return(a1.finish < a2.finish);
}

void Order(Act arr[], int n)
{
	sort(arr, arr+n, comp);

	cout<<"The Activities Selected are:";
	int i=0;
	cout<<"("<<arr[i].start<<", "<<arr[i].finish<<"), ";

	for(int j=1; j<n; j++)
	{
		if(arr[j].start >= arr[i].finish)
		{
			cout<<"("<<arr[j].start<<", "<< arr[j].finish<< "), ";
			i=j; 
		}
	}

}


int main()
{
	Act arr[] = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, 
                                       {5, 7}, {8, 9}}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    Order(arr, n); 
    return 0; 
}