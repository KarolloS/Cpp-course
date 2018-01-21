#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <string>
#include <time.h>
#include <conio.h>
#include <vector>
#include <memory>
#include <iomanip>

using namespace std;

class pozycja_bib
{
public:
	pozycja_bib() : ilosc_egz(0), autor(""), tytul(""), rok_wyd(""), czas_wyp(0) {}

	pozycja_bib(const int& n, string a, string t, string r, time_t c) : ilosc_egz(n), autor(a), tytul(t), rok_wyd(r), czas_wyp(c) {}

	virtual ~pozycja_bib() {}

	virtual int wypozycz()
	{
		if (ilosc_egz == 0)
		{
			cout << "brak dostepnych egzemplarzy !!!!" << endl << endl;
			return 0;
		}
		else
		{
			ilosc_egz--;
			return 1;
		}
	}

	virtual int zwroc()
	{
		ilosc_egz++;
		return 1;
	}

	virtual time_t get_t()
	{
		return czas_wyp;
	}

	virtual void drukuj() = 0;

protected:
	int ilosc_egz;
	string autor;
	string tytul;
	string rok_wyd;
	time_t czas_wyp;

};

class ksiazka : public pozycja_bib
{
public:
	ksiazka() : pozycja_bib() {}

	ksiazka(const int& n, string a, string t, string r, time_t c) : pozycja_bib(n, a, t, r, c) {}

	void drukuj()
	{
		cout << "Autor: " << autor << endl;
		cout << "Tytul: " << tytul << endl;
		cout << "Rok wydania: " << rok_wyd << endl;
		cout << "ilosc dostepnych egzemplarzy: " << ilosc_egz << endl;

		struct tm * data;
		data = localtime(&czas_wyp);
		char wyp[80];
		strftime(wyp, 80, "Okres wypozyczenia: %M minut %S sekund", data);

		cout << wyp << endl;
		cout << "__________" << endl;
	}

};

class artykul : public pozycja_bib
{
public:
	artykul() : pozycja_bib(), czasopismo(""), strony("") {}

	artykul(const int& n, string a, string t, string cz, string s, string r, time_t c) : pozycja_bib(n, a, t, r, c), czasopismo(cz), strony(s) {}

	void drukuj()
	{
		cout << "Autor: " << autor << endl;
		cout << "Tytul: " << tytul << endl;
		cout << "Czasopismo: " << czasopismo << endl;
		cout << "Strony: " << strony << endl;
		cout << "Rok wydania: " << rok_wyd << endl;
		cout << "ilosc dostepnych egzemplarzy: " << ilosc_egz << endl;

		struct tm * data;
		data = localtime(&czas_wyp);
		char wyp[80];
		strftime(wyp, 80, "Okres wypozyczenia: %M minut %S sekund", data);

		cout << wyp << endl;
		cout << "__________" << endl;
	}

private:
	string czasopismo;
	string strony;

};

typedef unique_ptr<pozycja_bib> pozycja_bib_ptr;

////////////////////////////////////////////////////////////

class wypozyczenie
{
public:
	wypozyczenie() : nr_pozycji(0), termin_zwr(0), kara(0) {}
	wypozyczenie(const int& n, time_t t) : nr_pozycji(n), kara(0)
	{
		time_t czas;
		time(&czas);
		termin_zwr = czas + t;
	}

	int get_termin_poz()
	{
		struct tm * data;
		data = localtime(&termin_zwr);
		char wyp[80];
		strftime(wyp, 80, "Termin zwrotu: %H:%M:%S", data);
		cout << wyp << endl;

		time_t czas, roznica;
		time(&czas);
		roznica = termin_zwr - czas;
		if (roznica < 0)
		{
			kara = -(double)roznica / 60;
			cout << fixed << setprecision(2);
			cout << "Minal termin zwrotu !!  Naliczona kara: " << kara << "zl  <1zl za kazda minute spoznienia>" << endl;
		}
		cout << endl;

		return nr_pozycji;
	}

	int get_nr()
	{
		return nr_pozycji;
	}

	double get_kara()
	{
		struct tm * data;
		data = localtime(&termin_zwr);

		time_t czas, roznica;
		time(&czas);
		roznica = termin_zwr - czas;
		if (roznica < 0)
		{
			kara = -(double)roznica / 60;
		}

		return kara;
	}

private:
	int nr_pozycji;
	double kara;
	time_t termin_zwr;

};

////////////////////////////////////////////////////////////

class uzytkownik
{
public:
	uzytkownik() :haslo("h") {}

	uzytkownik(string h) : haslo(h) {};

	void wypozycz(const int& n, time_t t)
	{
		wyp.push_back(wypozyczenie(n, t));
	}

	int zwroc(const int& n)
	{
		auto it = wyp.begin() + n - 1;
		int nr = it->get_nr();
		cout << "nr" << nr << endl;
		wyp.erase(wyp.begin() + n - 1);
		return nr;
	}

	int drukuj_poz_wyp(const int& n)
	{
		auto it = wyp.begin() + n;
		int p = it->get_termin_poz();
		return p;
	}

	int haslo_por(string haslo_w)
	{
		if (haslo == haslo_w)
			return 1;
		else
			return 0;
	}

	int zwr_wyp_n()
	{
		return wyp.size();
	}

	int czy_kara()
	{
		double kara = 0;
		suma_kara = 0;
		for (auto it = wyp.begin(); it != wyp.end(); ++it)
		{
			kara = it->get_kara();
			if (kara > 0)
			{
				suma_kara = suma_kara + kara;
			}
		}
		if (suma_kara > 0)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	double get_suma_kara()
	{
		return suma_kara;
	}
private:
	vector<wypozyczenie> wyp;
	string haslo;
	double suma_kara;
};

////////////////////////////////////////////////////////////

class biblioteka
{
public:
	biblioteka()
	{
		// pozycje biblioteczne
		spis_poz.push_back(pozycja_bib_ptr(new ksiazka(5, "jakis autor", "jakis tytul", "2009", 330)));
		spis_poz.push_back(pozycja_bib_ptr(new artykul(2, "jakis autor", "jakis tytul", "jakies czasopismo", "50-59", "2001", 15)));

		// uzytkownicy
		spis_uzt.push_back(uzytkownik("nikt"));
		spis_uzt.push_back(uzytkownik("h1"));
		spis_uzt.push_back(uzytkownik("h2"));

	}

	void start()
	{
		cout << "aby wyswietlic liste dostepnych pozycji do wypozyczenia wybierz [1]" << endl;
		cout << "aby sie zalogowac wybierz [2]" << endl;
		cout << "aby wyswietlic uzytkownikow z naliczonymi karami wybierz [3]" << endl;
		cout << "aby wyjsc wybierz [0]" << endl;

		int a;
		cin >> a;

		switch (a)
		{
		case 0:
			cout << endl;
			break;

		case 1:
			cout << endl << "________________________________________________________" << endl;
			drukuj_spis();
			cout << endl;
			start();
			break;

		case 2:
			zaloguj();
			break;

		case 3:
			cout << endl << "________________________________________________________" << endl;
			drukuj_uzt_kara();
			cout << endl;
			start();
			break;

		default:
			cout << endl << "bledna instrukcja" << endl << "________________________________________________________" << endl;
			start();
			break;
		}
	}

private:
	void drukuj_spis()
	{
		int n = 1;
		for (auto it = spis_poz.begin(); it != spis_poz.end(); ++it)
		{

			cout << "pozycja nr: " << n << endl << endl;
			it->get()->drukuj();
			n++;
		}
	}

	void drukuj_pozycje(const int& a)
	{
		auto it = spis_poz.begin() + a - 1;
		it->get()->drukuj();
	}

	void drukuj_uzt_kara()
	{
		int n = 1;
		for (auto it = spis_uzt.begin(); it != spis_uzt.end(); ++it)
		{
			if (it->czy_kara() == 1)
			{
				cout << "uzytkownik: " << n - 1 << "  sumaryczna naliczona kara: " << it->get_suma_kara() << endl;
			}
			n++;
		}
	}

	void zaloguj()
	{
		int status = 0;
		int nr_uzt;
		int max = spis_uzt.size();
		string haslo_uzt;
		cout << "podaj numer uzytkownika: ";
		cin >> nr_uzt;
		cout << "podaj haslo: ";
		cin >> haslo_uzt;


		if (nr_uzt<max && nr_uzt >= 1)
		{
			if (spis_uzt[nr_uzt].haslo_por(haslo_uzt))
			{
				zalogowany_uzt = nr_uzt;
				cout << "zalogowano uzytkownika o numerze: " << nr_uzt << endl;
				cout << endl << "________________________________________________________" << endl;
				zazadzaj();
			}
			else
			{
				status = -1;
			}
		}
		else
		{
			status = -1;
		}

		if (status == -1)
		{
			cout << "bledne haslo lub numer uzytkownika" << endl << endl;
			cout << "aby sie zalogowac ponownie wybierz [1]" << endl;
			cout << "aby wyjsc wybierz [0]" << endl;

			int a;
			cin >> a;

			switch (a)
			{
			case 0:
				cout << endl << "________________________________________________________" << endl;
				start();
				break;
			case 1:
				cout << endl;
				zaloguj();
				break;
			default:
				cout << endl << "bledna instrukcja" << endl << "________________________________________________________" << endl;
				start();
				break;
			}
		}
	}

	void wyloguj()
	{
		zalogowany_uzt = 0;
	}

	void zazadzaj()
	{
		int max1 = spis_poz.size();
		int max2 = spis_uzt[zalogowany_uzt].zwr_wyp_n();
		cout << "zalogowany uzytkownik nr: " << zalogowany_uzt << "      liczba wypozyczonych pozycji: " << max2 << endl << endl;

		cout << "aby wyswietlic liste dostepnych pozycji do wypozyczenia wybierz [1]" << endl;
		cout << "aby wypozyczyc nowa pozycje wybierz [2]" << endl;
		cout << "aby zwrocic pozycje wybierz [3]" << endl;
		cout << "aby wyswietlic liste wlasnych wypozyczen wybierz [4]" << endl;
		cout << "aby sie wylogowac wybierz [0]" << endl;

		int nr;
		int a;
		cin >> a;

		switch (a)
		{
		case 0:
			cout << endl << "________________________________________________________" << endl;
			wyloguj();
			start();
			break;

		case 1:
			cout << endl << "________________________________________________________" << endl;
			drukuj_spis();
			cout << endl;
			zazadzaj();
			break;

		case 2:
			int n1;
			cout << "podaj numer pozycji do wypozyczenia: ";
			cin >> n1;
			if (n1 > max1 || n1 < 1)
			{
				cout << "podana pozycja nie istnieje" << endl;
				cout << endl << "________________________________________________________" << endl;
				zazadzaj();
			}
			else
			{
				if (spis_poz[n1 - 1].get()->wypozycz())
				{
					spis_uzt[zalogowany_uzt].wypozycz(n1, spis_poz[n1 - 1].get()->get_t());
					cout << endl << "wypozyczono pozycje numer: " << n1 << endl;
				}
				cout << endl << "________________________________________________________" << endl;
				zazadzaj();
			}
			break;

		case 3:
			int n2;
			cout << "podaj numer pozycji do zwrocenia: ";
			cin >> n2;
			if (n2 > max2 || n2 < 1)
			{
				cout << "podana pozycja nie istnieje" << endl;
				cout << endl << "________________________________________________________" << endl;
				zazadzaj();
			}
			else
			{
				nr = spis_uzt[zalogowany_uzt].zwroc(n2);
				spis_poz[nr - 1].get()->zwroc();
				cout << endl << "zwrocono pozycje numer: " << n2 << endl;
				cout << endl << "________________________________________________________" << endl;
				zazadzaj();
			}
			break;

		case 4:
			int n3;
			cout << endl << "________________________________________________________" << endl;
			for (n3 = 0; n3 < max2; ++n3)
			{
				cout << "wypozyczona pozycja nr: " << n3 + 1 << endl;
				drukuj_pozycje(spis_uzt[zalogowany_uzt].drukuj_poz_wyp(n3));
			}
			cout << endl << "________________________________________________________" << endl;
			zazadzaj();
			break;

		default:
			cout << endl << "bledna instrukcja" << endl << "________________________________________________________" << endl;
			zazadzaj();
			break;
		}
	}

	vector<unique_ptr<pozycja_bib>> spis_poz;
	vector<uzytkownik> spis_uzt;

	int   zalogowany_uzt;
};
