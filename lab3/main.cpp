#include <iostream>
#include "pojazdy.h"
using namespace std;

//class A
//{
//public:
//    A()		{ cout << "konstruktor A\n"; }
//
//    ~A()    { cout << "destruktor A\n"; }
//
//	static int mattr;
//};
//
//int A::mattr = 0;
//
//int main()
//{
//    A   *ptr;
//    ptr = new A[5];
//
//
//	for (int i = 0; i<5; ++i)
//		ptr[i].mattr = i + 1;
//
//	for (int i = 0; i<5; ++i)
//		cout << "element " << i << " attr = " << ptr[i].mattr << endl;
//
//
//    delete [] ptr;
//    return 0;
//}


// metody klasy pojazd
pojazd::pojazd() : przebieg(0) { cout << "KP domyslny" << endl; }
pojazd::pojazd(const int& n) : przebieg(n) { cout << "KP parametryczny" << endl; }
pojazd::~pojazd() { cout << "DP" << endl; }
int pojazd::getPrzebieg() { return przebieg; }


// metody klasy autobus
autobus::autobus() : l(0), pojazd() { cout << "KA domyslny" << endl; }
autobus::autobus(const int& m) : l(m) { cout << "KA parametryczny 1" << endl; }
autobus::autobus(const int& m, const int& o) : l(m), pojazd(o) { cout << "KA parametryczny 2" << endl; }
autobus::~autobus() { cout << "DA" << endl; }

int autobus::getl() { return l; }


int main()
{
	//pojazd p(1596);
	//int prz = p.getPrzebieg();
	//cout << "przebieg = " << prz << endl;

	autobus a(9,15669);
	int l = a.getl();
	cout << "liczba pasazerow = " << l << endl;
	int prz = a.getPrzebieg();
	cout << "przebieg = " << prz << endl;

	return 0;
}