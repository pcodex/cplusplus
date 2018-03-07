// fnctor.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class MyFntor
{
	int anum;
public:
	MyFntor()
	{
		anum = 0;
	}

	int operator()()
	{
		anum += 10;
		return anum;
	}

	friend ostream& operator<<(ostream& os, MyFntor& mf)
	{
		os << mf.anum << "\n";
		return os;
	}
};

int main()
{
	MyFntor mfn = MyFntor();

	mfn();
	cout << mfn;
    return 0;
}

