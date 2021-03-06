// puboridedemo.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Base
{
	int bvar;

protected:
	virtual void showid()
	{
		cout << "\nIn Base::showid\n";
	}

public:

	Base(int in):bvar(in)
	{}

	virtual void updateval()
	{
		bvar += 10;
		cout << "\nIn Base::Updateval " << bvar;
	}

};

class Child : public Base
{
	int cvar;
public:
	Child(int in) :cvar(in), Base(in)
	{}

	virtual void showid()
	{
		Base::showid();
		cout << "\nIn Child::showid\n";
	}

	void updateval()
	{
		Base::updateval();
		cvar += 15;
		cout << "\nIn Child::Updateval " << cvar;
	}

};

class GChild :public Child
{
public:
	GChild(int a):Child(a)
	{}

	void updateval()
	{
		cout << "\nIn GChild::updateval";
	}
};

int main()
{
	Child cd(20);
	cd.showid();

	Base bobj(12);
	//bobj.showid(); //inaccessible
	Base* bptr = new Base(25);
	//bptr->showid(); //showid() is inaccessible

	bptr->updateval();//calls the Base version
	delete bptr;

	bptr = new Child(30);
	//bptr->showid(); //inaccessible

	bptr->updateval(); //calls the Child version
	delete bptr;

	bptr = new GChild(50);
	bptr->updateval();

	delete bptr;

    return 0;
}

