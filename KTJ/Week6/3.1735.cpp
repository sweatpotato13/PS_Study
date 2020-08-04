//https://www.acmicpc.net/problem/
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll gcd(ll a, ll b)
{
	if (b == 0)
		return a;
	else
		return gcd(b, a%b);
}

ll lcm(ll a, ll b)
{	
	ll ans = a * b / gcd(a, b);

	return ans;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll a1, a2, b1, b2, a,b;
	cin >> a1 >> b1 >> a2 >> b2;
	a = a1 * b2 + a2 * b1;
	b = b1 * b2;
	
	ll mod = gcd(a, b);

	if (mod != 0) {
		a = a / mod;
		b = b / mod;
	}

	cout << a << " " << b << "\n";
	system("pause");
	return 0;
}

