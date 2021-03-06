// changeaccess.cpp : Defines the entry point for the console application.
//


#include <iostream>
#include <vector>

using namespace std;

class Base
{	

protected:
	void incrval() {
		bval++;
		cout << "\nIn Base::incrval " << bval;
	}

public:
	int bval;
	
	Base(int num) :bval(num)
	{	}

	void display()
	{
		cout << "\nIn Base " << bval;
	}

	void basejunk()
	{
		cout << "\nIn Base junk";
	}
};


class Child :public Base
{
	int cval;
	using Base::bval; //change bval to  private in Child
	
public:
	Child(int num):cval(num),Base(num)
	{}

	using Base::incrval; //change access level from protected to public in Child

	void basejunk() = delete;//inaccessible from this class
	
};

int main()
{

	Base bs(10);
	bs.bval = 15; //access is public
	//bs.incrval(); //won't work since its protected and inaccessible
	bs.display();
	bs.basejunk();

	Child cp(20);
	//cp.bval = 10; //private so inaccessible via Child
	cp.incrval(); //call incrval() of Base
	cp.display();
	//cp.basejunk();//deleted function

    return 0;
}

