//https://www.acmicpc.net/problem/

#pragma warning (disable:4996)
//#define all(x) (x).begin(), (x).end()
#include <bits/stdc++.h>

typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector<int> met[1001];
map<int,int> visited;
map<int, int> visited2;

void DFS(int s) {
	if (visited[s] != 0)	return; //이미 방문 
	visited[s]++;
	cout << s << " ";
	for (int i = 0; i < met[s].size(); i++) {
		int y = met[s][i];
		DFS(y);
	}
}
void BFS(int s) {
	deque<int> visit;
	visit.push_back(s);
	visited2[s]++;

	while (visit.size() != 0) {
	
		int start = visit.at(0);
		visit.pop_front();
		cout << start << " ";
		for (int i = 0; i < met[start].size(); i++) {
			int y = met[start][i];
			//cout << i << " : " << y << endl;
			if (visited2[y] == 0) {
				visit.push_back(y);
				visited2[y]++;
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, s,nc=0;
	cin >> n >> m >> s;
	for (int i = 0; i < m; i++) {
		int start, end;
		cin >> start >> end;
		met[start].push_back(end);
		met[end].push_back(start);
	}

	for (int i = 0; i < n; i++) {
		sort(met[i].begin(), met[i].end());
	}


	DFS(s);
	cout << "\n";

	BFS(s);
	cout << "\n";

	system("pause");
	return 0;
}
