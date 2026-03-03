#include <string>
#include <iostream>
#include <locale>
#include <vector>
#include <algorithm>
#include <fstream>


using namespace std;


struct Song {
	string composer;
	string singer;
	double duration;
	unsigned int year;
};

void Print(const Song& s1)
{
	cout << s1.composer << "\n";
}

int main() {
	Song s{ "CC", "ss", 2.35, 1991 };
	Print(s);

}



bool func(string& s)
{
	if (s[s.size() -1 ] == 'a')
		return true;
	else return false;
}

void printVector(const vector<string>& v) {
	for (const auto& s : v)
		cout << s << "\n";
	cout << "***\n";
}


int main1()
{
	vector<string> v;
	v.push_back("yaroslav");
	v.push_back("ivan");
	v.push_back("kolya");
	v.push_back("vasya");

	vector<string>::iterator k, f, y;
	k = v.begin();

	y = std::find(v.begin() + 1, v.end(), "ivan");
	f = std::find(v.begin() + 1, v.end(), "masha");

	f = std::find_if(v.begin(), v.end(), func);
	
	if (f == v.end())
		cout << "not found\n";
	else 
		cout << *f << "\n";

	sort(v.begin(), v.end());
	for (auto& x : v)
		cout << x << " ";


	int kk = count(v.begin(), v.end(), "kolya");
	cout << kk << "\n";
    int p = count_if(v.begin(), v.end(), func);
	cout << p << "\n";

	return 0;
}
