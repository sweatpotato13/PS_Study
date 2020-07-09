#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;
// https://www.acmicpc.net/problem/14425
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n,m;
    cin >> n >> m;
    map<string,ll> ma;
    vector<string> v(n);
    for(int i = 0;i<n;i++){
        cin >> v[i];
    }
    for(int i = 0;i<m;i++){
        string s;
        cin >> s;
        ma[s]++;
    }
    ll ans = 0;
    for(auto k : v){
        ans += ma[k];
    }
    cout << ans;


    return 0;
}
