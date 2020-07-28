//https://www.acmicpc.net/problem/9372

#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

int BFS(int s, vector<int> *met) {
	deque<int> visit;
	map<int, int> visited2;
	visit.push_back(s);
	visited2[s]++;
	int ans = 0;
	while (visit.size() != 0) {

		int start = visit.at(0);
		visit.pop_front();
		//cout << start << " ";
		for (int i = 0; i < met[start].size(); i++) {
			int y = met[start][i];
			
			if (visited2[y] == 0) {
				visit.push_back(y);
				visited2[y]++;
				ans++;
			}
		}
	}
	return ans;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		vector<int> fly[1001];
		int n = 0, m = 0;
		cin >> n >> m;
		for (int i = 0; i < m; i++) {
			int start, end;
			cin >> start >> end;
			fly[start].push_back(end);
			fly[end].push_back(start);
		}
		cout<<BFS(1, fly)<<"\n";
	}

	system("pause");
	return 0;
}
