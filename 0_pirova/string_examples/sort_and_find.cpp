#include <string>
#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;

bool func(string& s)
{
	if (s[0] == 'y')
		return true;
	else return false;
}

void printVector(const vector<string>& v) {
	for (const auto& s: v)
		cout << s << "\n";
	cout << "***\n";
}

bool compare1(const string& s1, const string& s2) {
	return s1.length() < s2.length();
}

struct
{
	bool operator()(const string& s1, const string& s2) const 
	{ return s1.length() < s2.length(); }
}
customLess;

void main()
{
	vector<string> v;
	v.clear();
	v.push_back("yar");
	v.push_back("ivan");
	v.push_back("kolya");

	sort(v.begin(), v.end());

	printVector(v);

	sort(v.begin(), v.end(), std::greater<string>());
	printVector(v);

	sort(v.begin(), v.end(), customLess);
	printVector(v);

	sort(v.begin(), v.end(), compare1);

///////////////////////////////////////////////////////////////////////////////////

	int k = count(v.begin(), v.end(), "kolya");
	int p = count_if(v.begin(), v.end(), func);
	cout << k << " " << p << endl;
	auto x = find(v.begin(), v.end(), "kolya");
	cout << *x;
}
