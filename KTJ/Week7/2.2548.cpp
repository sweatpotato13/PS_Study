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
	ll e, ans = 0;
	vector <ll > arr;
	cin >> e;
	while (e--) {
		ll k;
		cin >> k;
		arr.push_back(k);
	}
	sort(all(arr));
	ll min = 10000000000;
	for (auto k : arr) {
		ll sums = 0;
		for (int i = 0; i < arr.size(); i++) {
			sums += abs(k - arr[i]);
		}
		if (min > sums) {
			ans = k;
			min = sums;
		}

	}
	cout << ans << "\n";
	system("pause");
	return 0;
}

