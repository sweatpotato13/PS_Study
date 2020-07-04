#include <iostream>
#include <map>
#include <algorithm>
#include <vector>
#include <math.h>
//1)에라토스의 체 2) 소인수분해 3)map에 저장 
using namespace std;
vector<int> prinum;
long long num = 40000;
long long arr[40001];
void aris() {
	for (long long i = 2; i <= num; i++) {
		arr[i] = i;
	}
	for (long long i = 2; i <= num; i++) {

		if (arr[i] == 0) // 이미 체크된 수의 배수는 확인하지 않는다
			continue;

		for (long long j = i + i; j <= num; j += i) { // i를 제외한 i의 배수들은 0으로 체크
			arr[j] = 0;
		}
	}
	for (int i = 2; i <=num; i++) {
		if (arr[i] != 0)	prinum.push_back(i);
	}
}
int main(void) {
	aris();
	unsigned long long int a = 0, b = 0, c = 0,ans=1;
	map<long long, long long> mapa;
	map<long long, long long> mapb;

	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> c;
			for (long long j = 0; j < prinum.size(); j++) {
				if (c == 1)	break;
				while (c%prinum.at(j) == 0) {
					mapa[prinum.at(j)]++;
					c = c / prinum.at(j);
				}
			}
			if (c != 1)
				mapa[c]++;
	}
	cin >> b;
	for (int i = 0; i < b; i++) {
		cin >> c;
		for (long long j = 0; j < prinum.size(); j++) {
			if (c == 1)	break;
			while (c%prinum.at(j) == 0) {
				mapb[prinum[j]]++;
				c = c / prinum.at(j);
			}
		}
		if (c != 1)
			mapb[c]++;
	}

	int q = 0;
	unsigned long long int mink;
	for (auto k : mapa ) {
		
		if (mapb[k.first] != 0) {
			mink = min(mapb[k.first], mapa[k.first]);
			for (int kk = 0; kk < mink; kk++) {
				ans *= k.first;
				if (ans >= 1000000000) {
					ans = ans % 1000000000;
					q++;
				}
			}
		}
		
	}

	if (q == 0)	cout << ans << endl;
	else {
		cout.width(9); // 폭을 9로 지정
		cout.fill('0'); // 채움 문자는 '0'
		cout << ans<<endl;
	}
	return 0;
}