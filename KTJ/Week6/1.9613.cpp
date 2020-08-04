//https://www.acmicpc.net/problem/9613
//유클리드 알고리즘 
// ctrl + k + f 
#pragma warning (disable:4996)
#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll T = 0;


int getGCD(int a, int b)
{
	if (b == 0)
		return a;
	else
		return getGCD(b, a%b);
}

int main()
{
	int T;
	cin >> T;

	for (int test_case = 0; test_case < T; test_case++)
	{
		int n;
		cin >> n;

		// 크기가 n인 벡터 생성 및 숫자들 입력받기
		vector<int> nums_vec(n);
		for (int i = 0; i < nums_vec.size(); i++)
			cin >> nums_vec[i];

		long long sum = 0;                                 // 자료형에 주의!!
		for (int i = 0; i < nums_vec.size() - 1; i++)
			for (int j = i + 1; j < nums_vec.size(); j++)
				sum += getGCD(nums_vec[i], nums_vec[j]);   // 최대공약수 : 유클리드 호제법 사용

		cout << sum << endl;
	}
	return 0;
}