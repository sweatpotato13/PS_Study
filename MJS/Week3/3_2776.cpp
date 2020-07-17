/*
  3. https://www.acmicpc.net/problem/2776
*/

#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <sstream>
#include <set>

using namespace std;

int main(void) {
	cin.tie(nullptr);

	set<int> ans;
	int temp = 0;
	int tCase = 0;
	int ansNum = 0;
	int qNum = 0;

	scanf("%d", &tCase);

	for (int i = 0; i < tCase; i++) {
		ans.clear();
		scanf("%d", &ansNum);
		for (int j = 0; j < ansNum; j++) {
			scanf("%d", &temp);
			ans.insert(temp);
		}

		scanf("%d", &qNum);

		for (int j = 0; j < qNum; j++) {
			scanf("%d", &temp);
			if (ans.count(temp) != 0) {
				printf("1\n");
			}
			else
				printf("0\n");
		}
	}

	return 0;
}