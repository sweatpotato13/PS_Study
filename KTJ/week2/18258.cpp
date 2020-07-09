#include <queue>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
using namespace std;
queue<long long> mque;

int main() {
	ios_base::sync_with_stdio(false);
	long long n;
	cin >> n;
	string s;
	for (int i = 0; i < n; i++) {
		
		cin >> s;
		if (!s.compare("push")) {
			long long x;
			cin >> x;
			mque.push(x);
		}
		else if (!s.compare("pop")) {
			if (mque.empty())
				cout << "-1" << "\n";
			else {
				cout << mque.front() << "\n";
				mque.pop();
			}
		}
		else if (!s.compare("front")) {
			if (mque.empty())
				cout << "-1" << "\n";
			else
				cout << mque.front() << "\n";
		}
		else if (!s.compare("back")) {
			if (mque.empty())
				cout << "-1" << "\n";
			else
				cout << mque.back() << "\n";
		}
		else if (!s.compare("empty")) {
			cout << mque.empty() << "\n";
		}
		else if (!s.compare("size")) {
			if (mque.empty())	cout << 0 << "\n";
			else cout << mque.size() << "\n";
		}
	}
	return 0;
}