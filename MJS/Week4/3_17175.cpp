/*
  3. https://www.acmicpc.net/problem/17175
*/

#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>

using namespace std;

int main(void) {
	cin.tie(nullptr);
	long long int n = 0;
	long long int res[51] = { 0, };

	res[0] = 1;
	res[1] = 1;
	
	scanf("%lld", &n);	
	
	for (int i = 2; i <= n; i++) {
		res[i] = (res[i - 1] + res[i - 2] + 1) % 1000000007;
	}
	
	printf("%lld", res[n]);

	return 0;
}