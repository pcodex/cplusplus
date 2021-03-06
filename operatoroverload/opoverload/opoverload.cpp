// opoverload.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class MyObject
{
	vector<int> container;

public:
	MyObject(vector<int> inp) :container(inp)
	{	}
	//called for non-const objects
	int& operator[](const int idx)
	{
		cout << "\nCalling Write operator \n";
		return container.at(idx);
	}

	//called for constant objects
	const int& operator[](const int idx) const
	{
		cout << "\nCalling Read operator \n";
		return container.at(idx);
	}

	friend ostream& operator<<(ostream& os, const MyObject& obj)
	{
		for (int i = 0; i < obj.container.size(); ++i)
			os << obj.container[i] << " ";
		os << "\n";

		return os;
	}

};


int main()
{
	vector<int> avect = { 2,4,5,6,7,8 };

	MyObject myo(avect);
	const MyObject myoc(avect);

	//cout << myo <<endl;

	myo[2] = 84; //non-const version

	cout << myo;
	cout << myo[2];

	int val = myoc[3]; //calls the const version
	cout << myoc[3] << " "<<val; //calls the const version

    return 0;
}

