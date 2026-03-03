#include <string>
#include <iostream>
#include <locale>
#include <vector>

using namespace std;

void main()
{
	string s1 = "hello";
	string letters = "aeoiu";
	std::size_t pos = s1.find_first_of(letters);
	cout << pos << "\n";
	cout << "all vowels\n";
	while (pos != std::string::npos)
	{
		pos = s1.find_first_of(letters, pos + 1);
		cout << pos << "\n";
	}

	// replase all vowels to Uppercase
	locale loc;
	pos = s1.find_first_of(letters);
	s1[pos] = toupper(s1[pos], loc);
	while (pos != std::string::npos)
	{
		pos = s1.find_first_of(letters, pos + 1);
		if (pos != std::string::npos)
			s1[pos] = toupper(s1[pos], loc);
	}
	cout << s1 << endl;

	// split to words
	std::getline(std::cin, s1);
	cout << "line: " << s1 << endl;

	// format string
	//s1.insert(s1.begin(), 3, ' ');
	cout << s1 << endl;
	int k = s1.find('.');
	vector<string> v;
	v.push_back(s1.substr(0, k));
	v.push_back(s1.substr(k + 1, s1.length() - (k + 1)));
	cout << v[0] << endl << v[1] << endl;
}
