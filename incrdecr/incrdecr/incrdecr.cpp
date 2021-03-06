// incrdecr.cpp : Defines the entry point for the console application.
//
#include <iostream>
#include <string>

using namespace std;

class MyInteger
{
	int myint;

public:
	MyInteger(int anum):myint(anum)
	{}

	MyInteger& operator++()
	{
		this->myint = (this->myint + 1)%10; //do whatever you wish here
		return *this;
	}

	MyInteger operator++(int)
	{
		MyInteger temp(this->myint);
		++(*this);//call the pre-increment

		return temp;//return old value
	}


	friend  ostream& operator<<(ostream& os, const MyInteger& val)
	{
		os << val.myint<<"\n";
		return os;
	}
};

int main()
{
	MyInteger arg1(29), arg2(30);
	cout << arg1 << arg2;

	++arg1;
	cout << arg1;
	++arg1;
	cout << arg1;

	cout << arg1++;
	cout << arg1;
    return 0;
}

