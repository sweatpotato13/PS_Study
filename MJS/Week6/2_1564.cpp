/*
	2. https://www.acmicpc.net/problem/1564
*/
//https://ko.numberempire.com/factorialcalculator.php
//https://ko.wikipedia.org/wiki/%EA%B3%84%EC%8A%B9#%EC%A0%90%EA%B7%BC_%EA%B3%B5%EC%8B%9D

#pragma warning(disable:4996)

#include <iostream>
using namespace std;

typedef unsigned long long ll;

int main(void) {
	cin.tie(nullptr);
	int input;
	ll result = 1;

	scanf("%d", &input);
	for (int i = 1; i <= input; i++) {
		result *= i;
		while (result % 10 == 0) {
			result /= 10;
		}
		result %= 1000000000000;
	}

	printf("%05llu", (result % 100000));

	return 0;
}