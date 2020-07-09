#include <queue>
#include <iostream>
#include <string>
using namespace std;
queue<int> mque;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push") {
			int x;
			cin >> x;
			mque.push(x);
		}
		else if (s == "pop") {
			if (mque.empty())
				cout << "-1" << "\n";
			else {
				cout << mque.front() << "\n";
				mque.pop();
			}
		}
		else if (s == "front") {
			if (mque.empty())
				cout << "-1" << "\n";
			else
				cout << mque.front() << "\n";
		}
		else if (s == "back") {
			if (mque.empty())
				cout << "-1" << "\n";
			else
				cout << mque.back() << "\n";
		}
		else if (s == "empty") {
			cout << mque.empty() << "\n";
		}
		else if (s == "size") {
			cout << mque.size() << "\n";
		}
	}
	return 0;
}