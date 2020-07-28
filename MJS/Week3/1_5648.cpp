/*
  1. https://www.acmicpc.net/problem/5648
*/

#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

string rev(string n) {
	while (n.back() == '0')
		n.pop_back();
	reverse(n.begin(), n.end());

	return n;
}

bool cmp(const string& a, const string& b)
{
	if (a.length() < b.length()) return true;
	else if (a.length() == b.length())
	{
		if (a < b) return true;
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);// cin, scanf 동시 사용 x 

	vector<string> v;
	string temp;
	int count = 0;

	scanf("%d", &count);

	for (int i = 0; i < count; i++) {
		cin >> temp;
		v.push_back(rev(temp));
	}

	sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		cout << i << endl;
	}

	return 0;
}