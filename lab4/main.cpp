#include <iostream>
#include <math.h>
using namespace std;

class Point
{
public:
	Point() : x(0), y(0) {}
	Point(const double& xx, const double& yy) : x(xx), y(yy) {}
	Point(const Point& p)
	{
		x = p.x;
		y = p.y;
		cout << "Point: Kontruktor kopiujacy" << endl;
	}

	double Length(const Point& p)
	{
		return sqrt((p.x - x)*(p.x - x) + (p.y - y)*(p.y - y));
	}

	double Length2(const Point p)
	{
		return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}

private:
	double x;
	double y;
};

class Shape
{
public:
	virtual void PrintName() { cout << "class Shape" << endl; }
	virtual double Area() = 0;
};

class Circle : public Shape
{
public:
	Circle() : p1(Point()), p2(Point()) {}
	Circle(const Point& pp1, const Point& pp2) : p1(pp1), p2(pp2) {}

	virtual void PrintName() { cout << "class Circle" << endl; }
	virtual double Area()
	{
		return 3.14*(p1.Length(p2))*(p1.Length(p2));
	}
private:
	Point p1;
	Point p2;
};

class Rectangle : public Shape
{
public:
	Rectangle() : p1(Point()), p2(Point()), p3(Point()), p4(Point()) {}
	Rectangle(const Point& pp1, const Point& pp2, const Point& pp3, const Point& pp4) : p1(pp1), p2(pp2), p3(pp3), p4(pp4) {}

	virtual void PrintName() { cout << "class Rectangle" << endl; }
	virtual double Area()
	{
		return (p1.Length(p2))*(p1.Length(p4));
	}
private:
	Point p1;
	Point p2;
	Point p3;
	Point p4;
};

int main()
{
	//    Point p1(2,4), p2(2,2);
	//    cout  << p1.Length(p2) <<endl;

	Point p1(0, 0), p2(4, 3);
	//    Circle c(p1,p2);
	//    c.PrintName(); 
	//    cout << c.Area() << endl;


	Point p3(0, 0), p4(4, 0), p5(4, 3), p6(0, 3);
	//    Rectangle r(p3,p4,p5,p6);
	//    r.PrintName(); 
	//    cout << r.Area() << endl;


	int count = 0;
	Shape   *tabp[2];
	tabp[0] = new Circle(p1, p2);
	tabp[1] = new Rectangle(p3, p4, p5, p6);
	for (int i = 0; i<2; ++i)
	{
		tabp[i]->PrintName();
		cout << tabp[i]->Area() << endl;

		if (dynamic_cast<Circle*>(tabp[i])){ count++; }
	}

	cout << count << endl;

	//    Point pa(10, 20), pb(30, 40);
	//    cout<<"Length()"<<endl;
	//    cout<<pa.Length(pb)<<endl;
	//    cout<<"Length2()"<<endl;
	//    cout<<pa.Length2(pb)<<endl;

	//delete [] tabp;

	return 0;
}