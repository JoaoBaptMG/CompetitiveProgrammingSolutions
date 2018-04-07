#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;
#define PRED(exp) ([](const auto& x){ return (exp); })

int main()
{
	string str;
	cin >> str;
	
	unordered_map<char,long> freqs;
	for (char c : str) freqs[c]++;
	
	bool possible;
	if (freqs.size() > 4) possible = false;
	else if (freqs.size() == 4) possible = true;
	else if (freqs.size() == 3)
		possible = any_of(freqs.begin(), freqs.end(), PRED(x.second > 1));
	else if (freqs.size() == 2)
		possible = all_of(freqs.begin(), freqs.end(), PRED(x.second > 1));
	else possible = false;
	
	cout << (possible ? "Yes" : "No") << endl;
}
