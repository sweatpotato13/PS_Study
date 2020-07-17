/*
  https://www.acmicpc.net/problem/1920
*/
#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	cin.tie(nullptr);

	long long int num = 0;
	long long int temp = 0;
	vector<long long int> v;

	scanf("%lld", &num);
	for (int i = 0; i < num; i++) {
		scanf("%lld", &temp);
		v.push_back(temp);
	}

	sort(v.begin(), v.end());

	scanf("%lld", &num);
	for (int i = 0; i < num; i++) {
		scanf("%lld", &temp);
		printf("%d\n", binary_search(v.begin(), v.end(), temp));
	}

	return 0;
}

