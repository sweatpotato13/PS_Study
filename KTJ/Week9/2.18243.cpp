//https://www.acmicpc.net/problem/
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;


vector <ll> adj[101];
ll n, k;
int bfs(ll x) {
	deque <ll> q;
	q.push_back(x);
	ll ndistance[101] = { 0, };
	bool visited[101] = { false, };
	visited[x] = true;
	ndistance[x] = 0;
	vector <ll> ans;
	ans.push_back(x);
	while (!q.empty()) {
		int dis;
		ll s = q.front(); q.pop_front();
		for (auto e : adj[s]) {
			if (visited[e] == true)	continue;
			visited[e] = true;
			ndistance[e] = ndistance[s] +1;
			//cout << ndistance[e] << " ";
			if (ndistance[e] > 6)	return -1;
			q.push_back(e);
			dis = ndistance[e];
			ans.push_back(e);
		}
		
	}
	if (ans.size() < n)	return -1;
	return 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	while (k--) {
		ll a, b;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans = 0;
	for (ll i = 1; i <= n;i++) {
		ans += bfs(i);
		//cout << "\n";
	}
	if (ans == 0)	cout << "Small World!" << "\n";
	else	cout << "Big World!" << "\n";
	system("pause");
	return 0;
}

