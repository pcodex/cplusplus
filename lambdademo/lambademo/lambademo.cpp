// lambademo.cpp : Defines the entry point for the console application.
//


#include <iostream>

using namespace std;



int main()
{
	int num = 0;
	float flt = 0.24f;

	//simple lambda
	auto lamfunc = []() {
		cout << "\nSimple Lambda function";
	};

	lamfunc();

	//pass all outer scope variables by value
	auto lamvalfunc = [=]() {		
		cout << "\nInside Lambda pass by value " << num;
	};

	lamvalfunc();

	//pass all outer scope by value but modify them
	auto lamvalchgfunc = [=]() mutable {
		num += 1;
		cout << "\nInside Lambda pass by value mutable " << num;
	};
	
	lamvalchgfunc();
	//value outside is unchanged
	cout << "\nOutside LamValChg() value is unchanged " << num;

	//pass all outer variables by ref
	auto lamreffunc = [&]()  {
		num += 1;
		flt = flt + 3.5f;
		cout << "\nInside Lambda pass by ref " << num<<" flt is "<<flt;
	};

	lamreffunc();
	//value outside is changed
	cout << "\nOutside lamreffunc() value is changed " << num <<" flt is "<<flt;

	//pass only selected variables by ref
	auto lamsel = [&flt]() {
		flt += 9.8;		
	};

	lamsel();
	cout << "\nAfter calling lamsel flt is " << flt;

	
    return 0;
}

