/*
	1. https://www.acmicpc.net/problem/9613
*/
#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
/*
3
4 10 20 30 40
3 7 5 12
3 125 15 25
*/
using namespace std;

int main(void) {
	cin.tie(nullptr);
	int t;
	int cnt;
	int input;

	int sieve[40001] = { 0, };

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

	scanf("%d", &t);
	for (int c = 0; c < t; c++) {
		scanf("%d", &cnt);
		map<int, int>* m = new map<int, int>[cnt];
		for (int c_ = 0; c_ < cnt; c_++) {
			scanf("%d", &input);
			for (int j = 1; j < 40000; j++) {
				if (sieve[j] == 0) {
					if (input % j == 0) {
						m[c_].insert(pair<int, int>(j, 0));
						int count = 0;

						while (input % j == 0) {
							input /= j;
							count++;
						}
						m[c_][j] += count;
					}
				}
			}
			if (input != 1) {
				m[c_].insert(pair<int, int>(input, 0));
				m[c_][input]++;
			}
		}
		long long total = 1;
		long long sum = 0;
		for (int i = 0; i < cnt; i++) {
			for (int j = i+1; j < cnt; j++) {
				//cout << i << " " << j << endl;
				total = 1;
				for (auto k : m[i]) {
					if (k.second != 0) {
						if (m[j].find(k.first) != m[j].end()) {
							if (k.second > m[j][k.first]) {
								//cout << "first: " << k.first << " second: " << m[j][k.first] << endl;
								total *= pow(k.first, m[j][k.first]);
							}
							else {
								//cout << "first: " << k.first << " second: " << k.second << endl;
								total *= pow(k.first, k.second);
							}
							//cout << "sum: " << total << endl;
						}
					}
				}
				sum += total;
			}
		}
		cout << sum << "\n";
	}
	return 0;
}

