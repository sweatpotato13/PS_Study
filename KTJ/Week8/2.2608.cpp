//https://www.acmicpc.net/problem/2608
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
map <char, ll> dic;
map <char, ll> cou;

ll chanum(string s) {
	ll chn = 0;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		chn += dic[c];
		cout << chn << " " << dic[c] << "\n";
	}
	cout << "\n";
	return chn;
}
string chastring(ll e) {
	string sans="";
	while (e != 0) {
		if (e >= 1000 && cou['M'] < 3) {
			cou['M']++;
			e = e - 1000;
			sans += 'M';
		}
		else if (e >= 500 && cou['D'] < 1) {
			cou['D']++;
			e = e - 500;
			sans += 'D';
		}
		else if (e >= 100 && cou['C'] < 3) {
			cou['C']++;
			e = e - 100;
			sans += 'C';
		}
		else if (e >= 50 && cou['L'] < 1) {
			cou['L']++;
			e = e - 50;
			sans += 'L';
		}
		else if (e >= 10 && cou['X'] < 3) {
			cou['X']++;
			e = e - 10;
			sans += 'X';
		}
		else if (e >= 5 && cou['V'] < 1) {
			cou['V']++;
			e = e - 5;
			sans += 'V';
		}
		else if (e >= 1 && cou['I'] < 3) {
			cou['I']++;
			e = e - 1;
			sans += 'I';
		}

	}
	return sans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	dic['I'] = 1;
	dic['V'] = 5;
	dic['X'] = 10;
	dic['L'] = 50;
	dic['C'] = 100;
	dic['D'] = 500;
	dic['M'] = 1000;
	string a, b;
	ll a1=0, b1=0,ans=0;
	cin >> a >> b;

	a1 = chanum(a);
	b1 = chanum(b);
	ans = a1 + b1;
	cout << ans << "\n";
	string ansstr= chastring(ans);
	cout << ansstr << "\n";
	system("pause");
	return 0;
}

