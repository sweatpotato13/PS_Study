//https://www.acmicpc.net/problem/10828
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int arr[10001] = { 0, };
int arrsize = 0;
int main(void) {
	int n = 0,num=0;
	cin >> n;
	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		if (s == "push") {
			cin >> num;
			arr[arrsize] = num;
			arrsize++;
		}
		else if (s == "pop") {
			if (arrsize == 0)	cout << -1 << endl;
			else {
				arrsize--;
				cout << arr[arrsize] << endl;
				arr[arrsize] = 0;
			}
		}
		else if (s == "size") {
			cout << arrsize << endl;
		}
		else if (s == "empty") {
			if (arrsize == 0)	cout << 1 << endl;
			else cout << 0 << endl;
		}
		else if (s == "top") {
			if (arrsize == 0) cout << -1 << endl;
			else
			{
				cout << arr[arrsize - 1] << endl;
			}
		}
	}
	system("pause");
	return 0;
}