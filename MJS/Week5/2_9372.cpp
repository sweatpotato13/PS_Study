/*
	2. https://www.acmicpc.net/problem/9372
*/

#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool isVisit[10001];
vector<int> v[10001];
int cnt = 0;

void dfs(int s) {
	isVisit[s] = true;

	for (long unsigned int i = 0; i < v[s].size(); i++) {
		if (isVisit[v[s].at(i)] != true) {
			cnt++;
			dfs(v[s].at(i));
		}
	}
}

int main(void) {
	cin.tie(nullptr);
	int t;
	int n, m;
	int f, e;
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d %d", &n, &m);
		memset(isVisit, false, sizeof(isVisit));

		for (int j = 0; j < m; j++) {
			scanf("%d %d", &f, &e);
			v[f].push_back(e);
			v[e].push_back(f);
		}

		for (int j = 0; j < 10001; j++) {
			sort(v[j].begin(), v[j].end());
		}
		
		dfs(n);
		
		printf("%d\n", cnt);
		cnt = 0;

		for (int j = 0; j < 10001; j++) {
			v[j].clear();
		}
	}
	return 0;
}