 //Convert integers into roman Numeral

#include<iostream>
#include<string.h>
using namespace std;

string conv (int num)
{
  string roman[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
  int val[] = { 1000, 900, 500, 400, 100, 50, 40, 10, 9, 5, 4, 1 };

  string result = "";

  for (int i = 0; i < 13; i++)
    {
        while (num - val[i] >= 0)
	    {
	        result = result + roman[i];
	        num = num - val[i];
	    }
    }

  return result;
}

int
main ()
{
  cout << conv (23456);
  return 0;
}
