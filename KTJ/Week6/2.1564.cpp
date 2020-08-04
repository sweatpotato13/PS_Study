//https://www.acmicpc.net/problem/
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
	ull n;
	ull fac=1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		fac = fac * i;
		while (fac % 10 == 0)	fac = fac / 10;
		fac = fac % 1000000000000;
	}
	
	cout.fill('0');
	cout.width(5);
	cout << fac%100000 << "\n";
	
	system("pause");
	return 0;
}

