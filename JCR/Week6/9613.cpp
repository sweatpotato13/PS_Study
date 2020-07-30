#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/9613
int input[100]={0,};
int gcd(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return gcd(b, a%b);
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	for(int i = 0;i<t;i++){
		int n;
		cin >> n;
		for(int j =0;j<n;j++){
			cin >> input[j];
		}
		ll sum = 0;
		for(int j = 0;j<n;j++){
			for(int k = j+1;k<n;k++){
				int a = max(input[j],input[k]);
				int b = min(input[j],input[k]);
				sum += gcd(a,b);
			}
		}
		cout << sum << "\n";
	}


	return 0;
}
