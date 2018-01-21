#include <string>
#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

bool mycomp(pair<int, string> p1, pair<int, string> p2)
{
	return p1.first<p2.first ? 1 : 0;
}

bool myiseq(pair<int, string> p1, pair<int, string> p2)
{
	return p1.first == p2.first ? 1 : 0;
}

int main()
{
	vector<pair<int, string>> myvect;
	vector<pair<int, string>>::iterator it;
	vector<pair<int, string>>::iterator it2;

	myvect.push_back(pair<int, string>(112, "s1"));
	myvect.push_back(pair<int, string>(112, "s2"));
	myvect.push_back(pair<int, string>(2, "s1"));
	myvect.push_back(pair<int, string>(2, "s3"));
	myvect.push_back(pair<int, string>(2, "s3"));
	myvect.push_back(pair<int, string>(111, "s4"));
	myvect.push_back(pair<int, string>(111, "s4"));

	for (it = myvect.begin(); it<myvect.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << "--------- sort -----------" << endl;
	sort(myvect.begin(), myvect.end(), mycomp);

	for (it = myvect.begin(); it<myvect.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << "--------- unique -----------" << endl;
	it2 = unique(myvect.begin(), myvect.end(), myiseq);

	for (it = myvect.begin(); it<myvect.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << "--------- erase -----------" << endl;
	myvect.erase(it2, myvect.end());
	for (it = myvect.begin(); it<myvect.end(); ++it)
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << "--------- lower bound -----------" << endl;
	it = lower_bound(myvect.begin(), myvect.end(), pair<int, string>(111, ""), mycomp);

	if (it != myvect.end())
	{
		cout << it->first << " " << it->second << endl;
	}

	cout << endl;
}