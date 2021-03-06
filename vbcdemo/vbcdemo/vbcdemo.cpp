// vbcdemo.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <vector>

using namespace std;

class GrandP
{
public:
	GrandP(int k)
	{
		cout << "\n In GrandP "<<k;
	}

	virtual void disp()
	{
		cout << "\n In GrandP disp";
	}
};

class Father : virtual public GrandP
{
public:
	Father(int v):GrandP(100)
	{
		cout << "\n In Father "<<v;
	}

	
};

class Mother : virtual public GrandP
{
public:
	Mother(int a) :GrandP(200)
	{
		cout << "\n In Mother "<<a;
	}

	virtual void disp()
	{
		cout << "\n In Mother disp";
	}
};

class Son : public Mother, public Father
{
public:
	Son():Father(10),Mother(20),GrandP(30)
	{
		cout << "\n In Son";
	}

	void disp()
	{
		cout << "\n In Son disp";
	}
};

int main()
{
	GrandP* ft = new Father(33);
	ft->disp(); //calls GrandP's disp

	GrandP* mt = new Mother(34);
	mt->disp();//calls Mother's disp

	GrandP* st = new Son; //calls the GrandP constructor with its initializer. does not use Father or Mother's intializers
	st->disp();

    return 0;
}

