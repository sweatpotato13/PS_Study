/*
	5. https://www.acmicpc.net/problem/10859
*/

#pragma warning(disable:4996)

#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;
typedef long long ll;
int sieve[40001] = { 0, };

bool IsPrimeNumber(ll num) {
	if (num == 2)
		return true;
	if ((num == 1))
		return false;
	if (num % 2 == 0)
		return false;
	for (ll n = 3; n < 40000; n++) {
		if (sieve[n] == 0) {
			if (num % n == 0)
			{
				if (num == n)
					break;
				else {
					return false;
				}
			}
		}
	}
	return true;
}

int main(void) {
	cin.tie(nullptr);
	string input;

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

	cin >> input;
	ll prime = stoll(input);
	if (IsPrimeNumber(prime) == true) {
		for (int i = 0; i < input.size(); i++) {
			if (input[i] == '3' || input[i] == '4' || input[i] == '7') {
				cout << "no";
				return 0;
			}
			else if (input[i] == '6') {
				input[i] = '9';
			}
			else if (input[i] == '9') {
				input[i] = '6';
			}
		}
		reverse(input.begin(), input.end());
		prime = stoll(input);
		if (IsPrimeNumber(prime) == true)
			cout << "yes";
		else
			cout << "no";
	}
	else
		cout << "no";

	return 0;
}