#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <functional>
#include <array>

using namespace std;


int main()
{
	cout << "start" << endl << endl;

	vector<int> tab;
	//    list<int> tab;
	int n = 4;

	// wypelnienie tablicy
	for (int i = 0; i<n; i++)
	{
		tab.push_back(2 * i);
		cout << "size " << tab.size() << endl;
	}

	cout << "_______________________" << endl;
	
	//for (int i=0;i<n;i++)
	//{
	//tab.insert( tab.end(), 2*i);
	//cout << tab.size() << endl;
	//}

	//cout << "_______________________" << endl;

	// drukowanie od poczatku
	vector<int>::iterator   itr;
	//    list<int>::iterator   itr;
	for (itr = tab.begin(); itr != tab.end(); ++itr)
		cout << *itr << endl;

	cout << "_______________________" << endl;

	// drukowanie od tylu
	vector<int>::reverse_iterator   ritr;
	//    list<int>::reverse_iterator   ritr;
	for (ritr = tab.rbegin(); ritr != tab.rend(); ++ritr)
		cout << *ritr << endl;

	cout << "_______________________" << endl;

	// sortowanie tablicy malejaco
	sort(tab.begin(), tab.end(), greater<int>());

	for (itr = tab.begin(); itr != tab.end(); ++itr)
		cout << *itr << endl;

	cout << "_______________________" << endl;

	// najmniejszy najwiekszy element

	cout << "max: " << *max_element(tab.begin(), tab.end()) << endl;
	cout << "min: " << *min_element(tab.begin(), tab.end()) << endl;

	cout << "_______________________" << endl;

	// czyszczenie tablicy
	tab.clear();
	cout << "size " << tab.size() << endl;
	cout << "empty? " << tab.empty() << endl;


	cout << endl;
	return 0;
}