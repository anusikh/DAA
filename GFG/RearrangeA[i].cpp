//Rearrange an array such that arr[i] = i

#include<bits/stdc++.h>
using namespace std;

void func(int arr[], int n) //n is the length of the array
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=-1 && arr[i]!=i)
		{
			int x = arr[i];

			while(arr[x]!=-1 && arr[x]!=x)
			{
				int y = arr[x];
				arr[x] = x;
				x = y;
			}

			arr[x] = x;

			if(arr[i]!=i)
			{
				arr[i] = -1;
			}
		}
	}
}			

int main()
{
    int A[] = { -1, -1, 6, 1, 9, 
               3, 2, -1, 4, -1 };
 
    int len = sizeof(A) / sizeof(A[0]);
    func(A, len);
    for (int i = 0; i < len; i++)
        cout << A[i] << " ";
}