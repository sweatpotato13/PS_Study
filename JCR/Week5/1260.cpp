#pragma warning (disable : 4996)
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

bool visit[1001];
vector<int> adj[1001];
queue<int> q;
int n, m, v;
void DFS(int v) {
    visit[v] = true;
    printf("%d ", v);
    for (int i = 0; i < adj[v].size(); i++) {
        if (!visit[adj[v].at(i)]) {
            DFS(adj[v].at(i));
        }
    }
}
void BFS(int v) {
    int idx = 0;
    if (!visit[v]) {
        visit[v] = true;
        printf("%d ", v);
    }
    for (int i = 0; i < adj[v].size(); i++) {
        if (!visit[adj[v].at(i)]) {
            q.push(adj[v].at(i));
            visit[adj[v].at(i)] = true;
            printf("%d ", adj[v].at(i));
        }
    }
    while (!q.empty()) {
        int res = q.front();
        q.pop();
        BFS(res);
    }
}
int main() {


    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        int e, s;
        scanf("%d %d", &e, &s);
        adj[e].push_back(s);
        adj[s].push_back(e);
    }

    for (int i = 0; i < n; i++) {
        sort(adj[i].begin(), adj[i].end());
    }

    DFS(v);
    printf("\n");
    memset(visit, 0, sizeof(visit));
    BFS(v);
    printf("\n");
    return 0;
}
