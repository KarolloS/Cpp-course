#include <string>
#include <iostream>

using namespace std;


template<class T>
class Singleton
{
public:
	static T*getInstance()
	{
		static T inst;
		return &inst;
	}
private:
	Singleton(){};
	Singleton(Singleton &s){};
};

class A
{

};

int main()
{
	A* a = Singleton<A>::getInstance();
}