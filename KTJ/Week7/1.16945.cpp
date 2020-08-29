//https://www.acmicpc.net/problem/
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll magicsqure(vector<vector <ll>> vec) {

	int all[8][3][3] = { {{8, 1, 6}, {3, 5, 7}, {4, 9, 2}},
					{{6, 1, 8}, {7, 5, 3}, {2, 9, 4}},
					{{8, 3, 4}, {1, 5, 9}, {6, 7, 2}},
					{{6, 7, 2}, {1, 5, 9}, {8, 3, 4}},
					{{4, 9, 2}, {3, 5, 7}, {8, 1, 6}},
					{{2, 9, 4}, {7, 5, 3}, {6, 1, 8}},
					{{2, 7, 6}, {9, 5, 1}, {4, 3, 8}},
					{{4, 3, 8}, {9, 5, 1}, {2, 7, 6}} };
	ll ans = INT_MAX;
	for (int i = 0; i < 8; i++) {
		ll temp = 0;
		for (int k = 0; k < 3; k++) {
			for (int j = 0; j < 3; j++) {
				temp = temp + abs(all[i][k][j] - vec[k][j]);
			}
		}
		ans=min(temp, ans);
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<ll>> arr(3);
	for (int i = 0; i < 3; i++) {
		arr[i].resize(3);
		for (int k = 0; k < 3; k++) {
			cin >> arr[i][k];
		}
	}

	ll ans = magicsqure(arr);
	cout << ans << "\n";
	system("pause");
	return 0;
}

