#include <iostream>
using namespace std;

class Wektor2D
{
public:
	Wektor2D();
	Wektor2D(const double& xx, const double& yy);
	void operator+=(Wektor2D& v);
	friend ostream& operator<<(ostream& os, const Wektor2D& w);
	friend bool operator>(const Wektor2D& w, const Wektor2D& v);
	void Drukuj();

private:
	double x;
	double y;
};
// -------------------------------------------------------------
// konstruktor domyœlny
Wektor2D::Wektor2D() :x(0), y(0)
{
}
// -------------------------------------------------------------
// konstruktor parametrowy
Wektor2D::Wektor2D(const double& xx, const double& yy) : x(xx), y(yy)
{
}
// -------------------------------------------------------------
// operator +=
void Wektor2D::operator+=(Wektor2D& v)
{
	x += v.x;
	y += v.y;
}
// ----------------------------------
// operator <<
ostream& operator<<(ostream& os, const Wektor2D& w)
{
	os << "wektor: [" << w.x << "," << w.y << "]" << endl;
	return os;
}
// ----------------------------------
// operator >
bool operator>(const Wektor2D& w, const Wektor2D& v)
{
	double l1, l2;
	l1 = sqrt(w.x * w.x + w.y *w.y);
	l2 = sqrt(v.x *v.x + v.y * v.y);

	if (l1 > l2) return 1;
	else return 0;

}
// ----------------------------------
// drukowanie wartoœci sk³adowych klasy
void Wektor2D::Drukuj()
{
	cout.setf(ios::fixed);
	cout << "wektor: [";
	cout.precision(3);
	cout.width(6);
	cout << x << ",";
	cout.precision(3);
	cout.width(6);
	cout << y << "]" << endl;
}

class Pojemnik
{
public:
	Pojemnik()
	{
		msize = 0;
		mdata = new Wektor2D[msize];
	}
	~Pojemnik()
	{
		delete[]mdata;
	}
	void Dodaj(const Wektor2D& v)
	{
		msize++;
		Wektor2D *temp = new Wektor2D[msize];
		for (int i = 0; i<(msize - 1); i++)
		{
			temp[i] = mdata[i];
		}
		temp[msize - 1] = v;
		delete[]mdata;
		mdata = temp;
	}
	void DrukujWszystko()
	{
		for (int i = 0; i<(msize); i++)
		{
			mdata[i].Drukuj();
		}
		cout << endl;
	}

	void DrukujWszystko2()
	{
		for (int i = 0; i<(msize); i++)
		{
			cout << mdata[i];
		}
		cout << endl;
	}
	Wektor2D Suma()
	{
		Wektor2D suma;
		for (int i = 0; i<(msize); i++)
		{
			suma += mdata[i];
		}
		return suma;
	}

	Wektor2D Max()
	{
		Wektor2D max = mdata[0];
		for (int i = 1; i<(msize); i++)
		{
			if (mdata[i]>max)
			{
				max = mdata[i];
			}
		}
		return max;
	}

private:
	Wektor2D *mdata;
	int msize;
};

void main()
{
	Wektor2D v1(4, 6);
	Wektor2D v2(0, 1);

	// cout << v1 << v2;

	Pojemnik poj;
	poj.Dodaj(v1);
	poj.Dodaj(v2);
	poj.Dodaj(Wektor2D(3, 2));
	poj.Dodaj(Wektor2D(8, 4));

	poj.DrukujWszystko2();

	Wektor2D sum = poj.Suma();
	sum.Drukuj();

	Wektor2D max = poj.Max();
	max.Drukuj();
}