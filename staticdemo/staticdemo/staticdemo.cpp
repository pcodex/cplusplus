// staticdemo.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

using namespace std;

class MyStatic
{
	int normalval;
	static int val;
	static vector<int> vval;
public:
	MyStatic()
	{
		normalval = 10;
		vval = { 1,2,4 };//can be initialized but not defined
		vval.push_back(39);
	}

	void disp()
	{
		statdisp(); //allowed
		cout << "\nNormal Value is " << normalval <<endl;
		cout << "\nStatic Value is " << val <<endl;
		for (int i = 0; i < vval.size(); ++i)
			cout << vval[i] << " ";
	}

	static void statdisp()
	{
		//cout << "\n Normal val is " << normalval; //not allowed
		cout << "\n Static val  is " << val<<endl;
		//disp(); //not allowed
	}
};
int MyStatic::val=8;
vector<int> MyStatic::vval;//you still need to define it


int main()
{
	MyStatic mys;

	mys.disp();

    return 0;
}

