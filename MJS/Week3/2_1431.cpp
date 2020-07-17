/*
  2. https://www.acmicpc.net/problem/1431
*/


#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <cctype>

using namespace std;

bool cmp(const pair<string, int>& a, const pair<string, int>& b)
{
	if (a.first.length() != b.first.length()) {
		return a.first.length() < b.first.length();
	}
	else
	{
		if (a.second != b.second)
		{
			return a.second < b.second;
		}
		else {

			return a.first < b.first;
		}
	}
}

int main(void) {
	vector<pair<string, int>> v;
	string temp;
	int count = 0;
	int cnt = 0;
	int length = 0;
	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		cin >> temp;
		cnt = 0;
		for (int i = 0; i < temp.length(); i++) {
			if (isdigit(temp[i])) {
				cnt += temp[i] - '0';
			}
		}
		v.push_back(make_pair(temp, cnt));
	}

	std::sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		cout << i.first << " " << i.second << endl;
	}

	return 0;
}