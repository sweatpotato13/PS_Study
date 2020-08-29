//https://www.acmicpc.net/problem/3107
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string s;
	cin >> s;
	int a=0;
	for (auto k : s) {
		if (k == ':') {
			a++;
		}
	}
	
	string sums;
	ll sumtt = 0;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		
		if (c == ':') {
			sumtt++;
			char c = s[i];
			if (sums.size() == 4) {
				cout << sums << ":";
				sums = "";
				
			}
			else {
				ll nums = 4-sums.size();
				for (int k = 0; k < nums; k++) {
					cout << 0;
				}
				cout << sums << ":";
				sums = "";
			}
		}
		else {
			sums += c;
			if (i==s.size()-1) {
				ll nums = 4 - sums.size();
				for (int k = 0; k < nums; k++) {
					cout << 0;
				}
				cout << sums<<"\n" ;
				
			}
		}
	}

	system("pause");
	return 0;
}

