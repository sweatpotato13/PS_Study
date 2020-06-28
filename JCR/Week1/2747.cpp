#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/2747
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll fibo[46] = {0,1,1,};
    ll n;
    cin >> n;
    for(int i = 3;i<=n;i++){
		fibo[i] = fibo[i-1]+fibo[i-2]; 
    }
    cout << fibo[n];

	return 0;
}