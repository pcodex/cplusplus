// delegateconstruct.cpp : Defines the entry point for the console application.
//

#include <iostream>

using namespace std;

class Tester
{
	int anum=0;
	int bnum=0;
	float fnum=0.0f;
public:
	Tester(int a, int b):anum(a),bnum(b)
	{
		cout << "\nIn the main constructor";
	}

	Tester(float a, int b, int c) : Tester(b,c)
	{
		cout << "\nIn the delegating constructor";
		//Tester(b, c); //this will not work
		fnum = a;
	}

	void display()
	{
		cout << "\n fnum is " << fnum
			<< "\n anum is " << anum
			<< "\n bnum is " << bnum;
	}
};


int main()
{
	Tester t1(20, 30);
	t1.display();

	Tester t2(2.3f, 40, 60);
	t2.display();

    return 0;
}

