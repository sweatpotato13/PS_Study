/*
	1. https://www.acmicpc.net/problem/1260
*/
#pragma warning(disable:4996)

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

bool isVisit[1001];
vector<int> v[1001];
queue<int> q;

void dfs(int s) {
	isVisit[s] = true;
	printf("%d ", s);

	for (long unsigned int i = 0; i < v[s].size(); i++) {
		if (isVisit[v[s].at(i)] != true)
			dfs(v[s].at(i));
	}
}

void bfs(int s) {
	isVisit[s] = true;
	q.push(s);

	while (!q.empty() && q.front()) {
		int f = q.front();
		q.pop();
		printf("%d ", f);

		for (long unsigned int i = 0; i < v[f].size(); i++)
			if (isVisit[v[f].at(i)] != true) {
				isVisit[v[f].at(i)] = true;
				q.push(v[f].at(i));
			}
	}
}

int main(void) {
	cin.tie(nullptr);
	int n, m, s;
	int f, e;
	scanf("%d %d %d", &n, &m, &s);
	memset(isVisit, false, sizeof(isVisit));

	for (int i = 0; i < m; i++) {
		scanf("%d %d", &f, &e);
		v[f].push_back(e);
		v[e].push_back(f);
	}

	for (int i = 0; i < 1001; i++) {
		sort(v[i].begin(), v[i].end());
	}

	dfs(s);
	printf("\n");
	memset(isVisit, false, sizeof(isVisit));
	bfs(s);
	return 0;
}