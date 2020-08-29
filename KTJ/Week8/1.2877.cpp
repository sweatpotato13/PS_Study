//https://www.acmicpc.net/problem/2877
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector <ll> arr;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll e = 0;
	cin >> e;
	arr.push_back(4);
	arr.push_back(7);
	while (arr.size() < e) {
		for (auto k : arr) {
			arr.push_back(k * 10 + 4);
			arr.push_back(k * 10 + 7);
		}
	}
	cout << arr[e-1] << "\n";
	system("pause");
	return 0;
}

