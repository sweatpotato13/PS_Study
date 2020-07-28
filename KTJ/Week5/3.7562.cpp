//https://www.acmicpc.net/problem/7562
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;

bool bound(ll x, ll y, ll l) {
	if (x >= 0 && x <= l - 1) {
		if (y >= 0 && y <= l - 1)
			return true;
		else return false;
	}
	else false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t;
	cin >> t;

	while (t--) {

		ll visit[301][301] = { 0, };
		ll visitcount[301][301] = { 0, };
		pair <ll, ll>  now, aim;
		deque <pair<ll, ll>> chess;
		ll n, x, y;
		cin >> n;
		cin >> x >> y;
		now.first = x;
		now.second = y;
		visit[x][y] = 1;
		chess.push_back({ x,y });

		cin >> x >> y;
		aim.first = x;
		aim.second = y;
		while (chess.size() != 0) {
			ll bre = 0;
			now = chess.front();
			chess.pop_front();
			ll nx = now.first;
			ll ny = now.second;
			ll vc = visitcount[nx][ny];
			vector <pair<ll, ll>> val;
			val.push_back({ now.first + 1,now.first + 2 });
			val.push_back({ now.first + 1,now.first - 2 });
			val.push_back({ now.first - 1,now.first + 2 });
			val.push_back({ now.first - 1,now.first - 2 });
			val.push_back({ now.first + 2,now.first + 1 });
			val.push_back({ now.first + 2,now.first - 1 });
			val.push_back({ now.first - 2,now.first + 1 });
			val.push_back({ now.first - 2,now.first - 1 });
			//cout << x << " " << y << "\n";
			for (int i = 0; i < val.size(); i++) {

				if (val[i].first == aim.first && val[i].second == aim.second) {
					cout << vc + 1 << "\n";
				}
				else if (visit[val[i].first][val[i].second] == 0) {//방문 전
					if (bound(val[i].first, val[i].second, n) == true) {
						visit[val[i].first][val[i].second] = 1;//방문
						visitcount[val[i].first][val[i].second] = vc + 1;
						chess.push_back({ val[i].first, val[i].second });
					}
				}
			}
			if (bre > 0)	break;
		}



	}

	system("pause");
	return 0;
}
