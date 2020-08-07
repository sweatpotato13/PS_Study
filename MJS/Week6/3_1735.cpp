/*
	3. https://www.acmicpc.net/problem/1735
*/

#pragma warning(disable:4996)

#include <iostream>
#include <cmath>
#include <map>

using namespace std;
typedef unsigned long long ll;

int main(void) {
	cin.tie(nullptr);
	map<int, int> m[2];
	int sieve[40001] = { 0, };
	ll a, b, c, d;
	ll res[2];

	for (int i = 0; i < 2; i++) {
		sieve[i] = 1;
	}

	for (int i = 2; i <= 40000; i++) {
		if (sieve[i] == 0) {
			for (int j = i + i; j < 40000; j += i) {
				sieve[j] = 1;
			}
		}
		else continue;
	}

	scanf("%llu %llu", &a, &b);
	scanf("%llu %llu", &c, &d);

	res[0] = (a * d) + (b * c);
	res[1] = b * d;

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 40000; j++) {
			if (sieve[j] == 0) {
				if (res[i] % j == 0) {
					m[i].insert(pair<int, int>(j, 0));
					int count = 0;

					while (res[i] % j == 0) {
						res[i] /= j;
						count++;
					}
					m[i][j] += count;
				}
			}
		}
		if (res[i] != 1) {
			m[i].insert(pair<int, int>(res[i], 0));
			m[i][res[i]]++;
		}
		res[i] = 1;
	}

	for (auto j : m[0]) {
		if (j.second != 0) {
			if (m[1].find(j.first) != m[1].end()) {
				if (j.second > m[1][j.first]) {
					m[0][j.first] -= m[1][j.first];
					m[1][j.first] = 0;
				}
				else {
					m[1][j.first] -= m[0][j.first];
					m[0][j.first] = 0;
				}
			}
		}
	}

	for (int i = 0; i < 2; i++) {
		for (auto j : m[i]) {
			if (j.second != 0) {
				res[i] *= pow(j.first, j.second);
			}
		}
		if (i == 0)
			printf("%llu ", res[i]);
		else
			printf("%llu", res[i]);
	}

	return 0;
}