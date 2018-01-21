#include <iostream>
using namespace std;

class Wektor2D
{
public:
	Wektor2D()
	{
		nr = indx;
		indx++;
		x = 0;
		y = 0;
		cout << "Konstruktor defaultowy     nr=" << nr << "        x=" << x << ", y=" << y << endl;
	}

	Wektor2D(const double& xx, const double& yy) : x(xx), y(yy)
	{
		nr = indx;
		indx++;
		cout << "Konstruktor parametryczny  nr=" << nr << "        x=" << x << ", y=" << y << endl;
	}

	Wektor2D(const Wektor2D& v)
	{
		nr = indx;
		indx++;
		x = v.x;
		y = v.y;
		cout << "Konstruktor kopiujacy      nr=" << nr << "        x=" << x << ", y=" << y << endl;
	}

	~Wektor2D()
	{
		cout << "Destruktor                 nr=" << nr << "        x=" << x << ", y=" << y << endl;
	}

	void Drukuj()
	{
		cout << "wektor[" << x << ", " << y << "]" << endl;
	}

	int SetX(const double& xx)
	{
		if (xx>100)
		{
			return 1;
		}

		x = xx;
	}

	double GetX()
	{
		return x;
	}

	int SetY(const double& yy)
	{
		if (yy>100)
		{
			return 1;
		}

		y = y;
	}

	double GetY()
	{
		return y;
	}

	friend Wektor2D& operator+ (const Wektor2D& v1, const Wektor2D& v2);

	Wektor2D& operator+= (const Wektor2D& v)
	{
		x = x + v.x;
		y = y + v.y;

		return *this;
	}

private:
	double x;
	double y;
	static int indx;
	int nr;
};

int Wektor2D::indx = 1;

Wektor2D& operator+ (const Wektor2D& v1, const Wektor2D& v2)
{
	Wektor2D temp;
	temp.x = v1.x + v2.x;
	temp.y = v1.y + v2.y;
	return temp;
}

void main()
{
	Wektor2D v1(10, 20);
	Wektor2D v2 = v1;
	Wektor2D v3(v1);
	Wektor2D v4;
	v1.Drukuj();
	v2.Drukuj();
	v3.Drukuj();
	v4.Drukuj();

	v4 = v1 + v2;
	v4.Drukuj();
	v3 += v3;
	v3.Drukuj();

	v4.SetX(50);
	v4.Drukuj();
	Wektor2D v5(v4.GetY(), v3.GetX());
	v5.Drukuj();

}