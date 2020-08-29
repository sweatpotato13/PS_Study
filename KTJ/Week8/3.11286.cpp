//https://www.acmicpc.net/problem/11286
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector <ll> s;
map <ll, ll> cou;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll e = 0;
	cin >> e;

	while (e--) {
		ll k = 0;
		cin >> k;
		
		if (k == 0) {
			ll l = 0;
			for (auto j : cou) {
				if (j.second != 0) {
					j.second=0;
					cout << j.first;
					l = 1;
					break;
				}
			}
			if (l == 1) {
				cout << 0 << "\n";
			}
		}

		else {
			cou[k]++;
		}
		
	}

	system("pause");
	return 0;
}

