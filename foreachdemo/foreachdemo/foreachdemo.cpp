// foreachdemo.cpp : Defines the entry point for the console application.
//

#include <vector>
#include <iostream>

using namespace std;

class Demo
{
	vector<int> vals;
public:
	Demo(vector<int> v):vals(v)
	{}

	void mod()
	{
		for (int& vone : vals) //use a ref
		{
			vone += 11;
		}
	}

	void disp()
	{
		for (const int& sv : vals)//use a const ref
		{
			cout << sv <<" ";			
		}
		cout << "\n";
	}
};

int main()
{
	vector<int> t = { 2,4,5,7 };
	Demo dd(t);

	dd.disp();
	dd.mod();

	dd.disp();
    return 0;
}

