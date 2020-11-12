#include<iostream>
using namespace std;

class Weight
{
private:
	int kg;
public:
	Weight()
	{
		kg = 0;
	}

	Weight(int x)
	{
		kg = x;
	}

	void Print()
	{
		cout<<"Weight is:"<<kg;
	}

	void operator ++()
	{
		++kg;
	}

	void operator ++(int)
	{
		kg++;
	}

	void operator --()
	{
		--kg;
	}

	void operator --(int)
	{
		--kg;
	}

	Weight operator ++()
	{
		Weight temp;
		temp.kg = ++kg;
		return temp;
	}
};

int main()
{
	/*Weight w1(10);
	++w1;
	w1.Print();
	return 0;*/

	Weight w1,w2;
	w2 = ++w1;

	w2.Print();
	return 0;
}