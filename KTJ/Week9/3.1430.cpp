//https://www.acmicpc.net/problem/1430
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>
#include <cmath>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

vector <ll> adj[101];
vector <pair<int, int>> xypair;
int n, r, d, x, y;
ll bfs(int x) {
	deque <ll> q; 
	int ndistance[101] = { 0, };
	bool visited[101] = { false, };
	q.push_back(x);
	ndistance[x] = 0;
	visited[x] = true;
	while (!q.empty()) {
		ll k = q.front(); q.pop_front();
		for (auto e : adj[k]) {
			if (visited[e])	continue;
			visited[e] = true;
			ndistance[e] = ndistance[k] + 1;
			q.push_back(e);
		}
	}
	ll num = 0; 
	for (int i = 1; i <= n; i++) {
		num += 10 * pow(1 / 2, ndistance[0]+1);
		cout << ndistance[0]<<" "<<num;
		return num;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> r >> d >> x >> y;
	xypair.push_back({ x, y });
	while (n--) {
		ll a, b;
		cin >> a >> b;
		xypair.push_back({a, b});
	}
	int i = 0, k = 0;
	for (int i = 0; i < xypair.size();i++) {//xypair[0]부터 입력 
		int x1 = xypair[i].first;
		int y1 = xypair[i].second;
		//cout << x1 << y1 << "\n";
		for (int q = 1; q<xypair.size(); q++) {
			if (i == q)	continue;
			int x2 = xypair[q].first;
			int y2 = xypair[q].second;
			
			ll distcalca = sqrt(pow(x1-x2,2) + pow(y1-y2,2));
			//cout << distcalca << "\n";
			if (distcalca <= r) {
				adj[i].push_back(q);
				cout << i << ":" << q << "\n";
			}
		}
	}

	ll ans = -19999;
	for (auto e : adj[0]){
		ll temp = bfs(e);
		ans=max(ans,bfs(e));
		
	}
	cout << ans << "\n";
	system("pause");
	return 0;
}

