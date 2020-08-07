#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/2750
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    sort(all(v));
    for(auto k : v){
        cout << k << "\n";
    }

	return 0;
}