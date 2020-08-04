//https://www.acmicpc.net/problem/10859
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll num = 10000000000000001;


bool isPrime(ll num) {
	if (num == 1) return false;
	if (num == 2) return true;
	for (ll i = 2; i*i <= num; i++) {
		if (num % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll e = 0; 
	cin >> e;
	deque <int> pnum;
	int pass = 0;
	while (e > 0) {
		ll q = e % 10;
		if (q == 3 || q == 4 || q == 7) {
			cout << "no" << "\n";
			pass = 1;
			break;
		}
		else if (q == 6)	q = 9;
		else if (q == 9)	q = 6;
		pnum.push_front(q);
		e = e / 10;
	}
	if (pass == 0) {
		ll prinum = 0;
		ll ten = 1;
		for (auto k : pnum) {
			prinum = prinum + (k * ten);
			ten = ten * 10;
		}

		if (isPrime(prinum))	cout << "yes" << "\n";
		else cout << "no" << "\n";
	}
	

	system("pause");
	return 0;
}

