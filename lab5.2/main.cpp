#include <iostream>
#include <math.h>
using namespace std;

template< class T, int N >
class Wektor2D
{
public:
	Wektor2D() :x(0), y(0) {};

	Wektor2D(const T& xx, const T& yy) : x(xx), y(yy) {};

	void operator+=(Wektor2D<T, N>& v)
	{
		x += v.x;
		y += v.y;
	}

	template < class TT, int NN >
	friend bool operator>(Wektor2D<TT, NN>& v1, Wektor2D<TT, NN>& v2);

	template < class TT, int NN >
	friend ostream& operator<<(ostream& os, const Wektor2D<TT, NN>& w);

	void Drukuj()
	{
		cout << "wektor: [";
		cout << x << ",";
		cout << y << "]" << endl;
	}


private:
	T x;
	T y;
};

template < class T, int N >
bool operator>(Wektor2D<T, N>& v1, Wektor2D<T, N>& v2)
{
	double l1, l2;
	l1 = sqrt(v1.x*v1.x + v1.y*v1.y);
	l2 = sqrt(v2.x*v2.x + v2.y*v2.y);

	if (l1>l2) { return 1; }
	else { return 0; }

}

template < class T, int N >
ostream& operator<<(ostream& os, const Wektor2D<T, N>& w)
{
	os << "wektor: [" << w.x << "," << w.y << "]" << endl;
	return os;
}

template <>
ostream& operator<<(ostream& os, const Wektor2D<double, 0>& w)
{
	os << "typ DOUBLE wektor: [" << w.x << "," << w.y << "]" << endl;
	return os;
}



template <typename T, typename W, typename R>
R mymax(T a, W b)
{
	if (a>b) { return a; }
	else { return b; }
}

int main()
{
	//cout << "start" << endl;

	//cout << mymax<double,int,double>( 5.5, 8) << endl;

	Wektor2D<double, 5> w1(1.6, 3.8), w2(3.4, 5.6);
	//Wektor2D<double> w3 = mymax<Wektor2D<double>, Wektor2D<double>, Wektor2D<double>>(w1, w2);
	//w3.Drukuj();

	cout << mymax<Wektor2D<double, 5>, Wektor2D<double, 5>, Wektor2D<double, 5>>(w1, w2);
	return 0;
}