#include <iostream>
#include<string>
#include<map>

using namespace std;

class Base
{

};

class Factory
{
public:
	template<typename T>
	void Add(string str, T* t)
	{
		mymap[str] = t;
	}

	Base* create(string str)
	{
		return mymap[str];
	}

private:
	map<string, Base*> mymap;
};

int main()
{
	Factory f;
	//f.Add("A".new A());
	//f.Add("B".new B());
	//f.Add("C".new C());

}