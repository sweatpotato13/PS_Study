//https://www.acmicpc.net/problem/11502
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
vector <ll> arinum;
bool prinum(int num) {
	if (num == 1)	return false;
	if (num == 2)	return true;
	else {
		for (int k = 2; k*k <= num; k++) {
			if (num%k == 0)	return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll t = 0;
	cin >> t;
	vector <ll> ans;
	for (int i = 2; i < 1001; i++) {
		if (prinum(i)) {
			arinum.push_back(i);
			//cout << i << " ";
		}
	}
	
	while (t--) {
		ll e;
		cin >> e;
		for (int i = 0; i < arinum.size(); i++) {
			for (int k = 0;k<arinum.size() && (e - arinum[i] >= arinum[k]); k++) {
				for (int j = 0; j<arinum.size() && (e - arinum[i] - arinum[k] >= arinum[j]); j++) {
					if (arinum[i] + arinum[k] + arinum[j] == e) {
						ans.push_back(arinum[i]);
						ans.push_back(arinum[j]);
						ans.push_back(arinum[k]);
						
						sort(all(ans));
						goto ena;

					}
				}
			}
		}	
		ena:
		if (ans.size() == 3) {
			for (int i = 0; i < 3; i++) {
				cout << ans[i] << " ";
			}
		}
		else {
			cout << "0";
		}
		cout << "\n";

	}


	system("pause");
	return 0;
}

