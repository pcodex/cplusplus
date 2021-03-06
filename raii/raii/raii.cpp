// raii.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

class MyInteger
{
	int* anint;

public:
	MyInteger(int a)
	{		
		anint = new int(a);
	}

	~MyInteger()
	{		
		cout << "\nDestructor called for " << *anint << "\n"; //object yet to be deleted
		delete anint;
	}

	friend ostream& operator<<(ostream& os, const MyInteger& val)
	{
		os << *val.anint << "\n";
		return os;
	}
};

int main()
{

	MyInteger myint(20); //RAII - created on stack. destructor will be automatically called when it goes out of scope.
	cout << myint;

	MyInteger* aval = new MyInteger(30);
	cout << *aval;

	delete aval; //not RAII - should explicitly call the destructor

    return 0;
}

