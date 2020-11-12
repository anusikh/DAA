#include<iostream>
#include<climits>
using namespace std;

int Egg(int e, int f)
{
	if(e==1)
		return f;
	if(f==0||f==1)
		return f;

	int min = INT_MAX, temp;

	for(int k=1;k<=f;k++)
	{
		temp = 1 + std::max(Egg(e-1,k-1),Egg(e,f-k));
		if(temp<min)
			min = temp;
	}
	return min;
}

int main()
{
	cout<<Egg(2,10);
	return 0;
}
