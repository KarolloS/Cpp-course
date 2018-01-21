#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include "library.cpp"

using namespace std;


int main()
{

	cout << "Wirtualna biblioteka" << endl << endl;

	biblioteka bib;
	bib.start();


	return 0;
}