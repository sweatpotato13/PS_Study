/*
  5. https://www.acmicpc.net/problem/3079
  2805, 2110, 2512, 2343, 3691
*/

#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long ll;

int main(void) {
	cin.tie(nullptr);
	int input = 0;
	ll m, n;
	ll l = 0;

	scanf("%lld %lld", &m, &n);
	vector<ll> v(m);

	for (int i = 0; i < m; i++) {
		scanf("%d", &input);
		v[i] = input;
	}
	sort(v.begin(), v.end());

	ll h = n * v[m - 1];
	ll ans = h;

	while (l <= h) {
		ll mid = (l + h) / 2;
		ll temp = 0;

		for (int i = 0; i < m; i++) {
			temp += (mid / v[i]);
		}

		if (temp >= n) {
			ans = min(ans, mid);
			h = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}

	cout << ans;

	return 0;
}