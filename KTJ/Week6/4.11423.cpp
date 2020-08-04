//https://www.acmicpc.net/problem/11423
//�Ҽ� ���ϱ� : �����佺�׳׽��� ü 
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll num = 10000001;
ll pri[10000001] = { 0, };

void getprime() {
	for (int i = 2; i < num; i++) {
		pri[i] = i;
	}
	for (int i = 2; i < num; i++) {

		if (pri[i] == 0)//�Ҽ��� �ƴ� 
			continue;
		for (int j = i + i; j <= num; j += i) {
			pri[j] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	getprime();
	while (true) {
		ll m, n;
		cin >> m >> n;
		if (cin.eof())	break;
		ll ans = 0;
		for (int i = m; i <= n; i++) {
			if (pri[i] != 0)	ans++;
		}
		cout << ans << "\n\n";
	}
	system("pause");
	return 0;
}

