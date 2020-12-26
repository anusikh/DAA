//Kth smallest element using heap

#include<iostream>
#include<queue>
using namespace std;

int
main ()
{
  priority_queue < int >maxheap;
  int k;
  cin >> k;
  int size = 6;
  int arr[] = { 7, 10, 4, 3, 20, 15 };

  for (int i = 0; i < size; i++)
    {
      maxheap.push (arr[i]);
      if (maxheap.size () > k)
	{
	  maxheap.pop ();
	}
    }

  cout << maxheap.top ();
  return 0;
}
