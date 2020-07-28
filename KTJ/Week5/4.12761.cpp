//https://www.acmicpc.net/problem/12761
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll visit[100001] = { 0, };
ll visitcount[100001] = { 0, };
deque <ll> node;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll A, B, N, M, ans = 0;
	cin >> A >> B >> N >> M;

	visit[N] = 1;//방문
	node.push_back(N);

	while (node.size() != 0) {
		N = node.front();
		node.pop_front();
		ll vc = visitcount[N];
		//cout << vc << " " << "\n";
		//cout << N << " : " << visitcount[N] << "\n";
	
		ll val[8];
		val[0] = N + 1;
		val[1] = N - 1;
		val[2] = N * A;
		val[3] = N * B;
		val[4] = N + A;
		val[5] = N + B;
		val[6] = N - A;
		val[7] = N - B;
	
		for (int i = 0; i < 8; i++) {
			if (val[i] == M) {
				cout<<vc+1 << "\n";
				goto theend;
			}
			else if (val[i] >= 0 && val[i] <= 100000 && visit[val[i]] == 0) {// 나오지 않음 
				
				node.push_back(val[i]);
				visit[val[i]] = 1;
				visitcount[val[i]] = vc+1;
				
			}
		}
	}
	theend:
	system("pause");
	return 0;
}
