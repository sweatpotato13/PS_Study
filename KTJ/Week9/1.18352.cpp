//https://www.acmicpc.net/problem/18352
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector <ll> ans;
ll n, m, k, x;
ll ndistance[300001] = { 0, };
bool visited[300001] = { false, };
vector <ll> adj[300000];

void bfs(ll x) {
	deque <ll> q;
	q.push_back(x);
	visited[x] = true;
	ndistance[x] = 0;
	while (!q.empty()) {
		int dis;
		ll s = q.front(); q.pop_front();
		for (auto e : adj[s]) {
			if (visited[e]==true)	continue;
			visited[e] = true;
			ndistance[e] = ndistance[s] + 1;
			if (ndistance[e] == k)	ans.push_back(e);
			q.push_back(e);
			dis = ndistance[e];
		}
		if (dis > k)	return;
	}
	
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n >> m >> k >> x;
	while (m--) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}
	sort(adj->begin(),adj->begin());
	bfs(x);
	sort(all(ans));
	for (auto e : ans) {
		cout << e << "\n";
	}
	if (ans.empty())	cout << "-1";

	system("pause");
	return 0;
}