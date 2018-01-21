#ifndef POJAZDY_H
#define POJAZDY_H

class pojazd
{
public:
	pojazd();
	pojazd(const int& n);
	virtual ~pojazd();

	int getPrzebieg();

private:
	int przebieg;

};


class autobus : public pojazd
{
public:
	autobus();
	autobus(const int& m);
	autobus(const int& m, const int& o);
	virtual ~autobus();

	int getl();

private:
	int l;
};

#endif


