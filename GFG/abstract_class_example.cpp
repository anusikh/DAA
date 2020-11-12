#include<iostream> 
using namespace std; 

class Base 
{ 
public: 
	virtual void show()
    {
    	cout<<"Hello";
    }
}; 

class Derived: public Base 
{ 
public: 
	void show() { cout << "In Derived \n"; } 
}; 

int main(void) 
{ 
	Base *bp = new Derived(); 
	bp->show(); 
	return 0; 
}


//the output is "In Derived", but if we remove virtual then output will be "Hello" 