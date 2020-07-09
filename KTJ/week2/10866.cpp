#include <queue>
#include <deque>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
deque<int> mque;

int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		if (s == "push_front") {
			int x;
			cin >> x;
			mque.push_front(x);
		}
		if (s == "push_back") {
			int x;
			cin >> x;
			mque.push_back(x);
		}
		else if (s == "pop_front") {
			if (mque.empty())
				cout << "-1" << "\n";
			else {
				cout << mque.front() << "\n";
				mque.pop_front();
			}
		}
		else if (s == "pop_back") {
			if (mque.empty())
				cout << "-1" << "\n";
			else {
				cout << mque.back() << "\n";
				mque.pop_back();
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