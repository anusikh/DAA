#include<iostream>
using namespace std;

class Complex
{
private:
	int real, imag;
public:
	Complex()
	{
		real = 0;
		imag = 0;
	}
	Complex(int r, int i)
	{
		real = r;
		imag = i;
	}

	void Print()
	{
		cout<<real<<"+"<<imag<<"i";
	}

	Complex operator +(Complex c)
	{
		Complex temp;
		temp.real = real+c.real;
		temp.imag = imag+c.imag;
		return temp;
	}
};

int main()
{
	Complex c1(5,4);
	Complex c2(4,3);
	Complex c3;
	c3 = c1+c2;

	c3.Print();
	return 0;
}