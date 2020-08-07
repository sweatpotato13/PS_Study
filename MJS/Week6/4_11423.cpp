/*
	4. https://www.acmicpc.net/problem/11423
*/

#pragma warning(disable:4996)

#include <iostream>
#include <cstring>

using namespace std;

int main(void) {
	cin.tie(nullptr);
	int inputs;
	int inpute;
	bool* sieve = new bool[10000001];
	memset(sieve, false, sizeof(bool) * 10000001);
	for (int i = 0; i < 2; i++) {
		sieve[i] = true;
	}
	for (int i = 2; i <= 10000000; i++) {
		if (sieve[i] == false) {
			for (int j = i + i; j <= 10000000; j += i) {
				sieve[j] = true;
			}
		}
		else continue;
	}
	while (true) {
		int cnt = 0;

		cin >> inputs >> inpute;
		if (cin.eof())
			break;
		for (int i = inputs; i <= inpute; i++) {
			if (sieve[i] == false) 
				cnt++;
		}
		printf("%d\n\n", cnt);
	}

	return 0;
}