#include <bits/stdc++.h>
using namespace std;
deque<int>lst;
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "push_front") {
            int x; 
            cin >> x;
            lst.push_front(x);
        }
        else if (str == "push_back") {
            int x; 
            cin >> x;
            lst.push_back(x);
        }
        else if (str == "pop_front") {
            if (lst.empty())
                cout << "-1" << "\n";
            else {
                cout << lst.front() << "\n";
                lst.pop_front();
            }
        }
        else if (str == "pop_back") {
            if (lst.empty())
                cout << "-1" << "\n";
            else {
                cout << lst.back() << "\n";
                lst.pop_back();
            }
        }         
        else if (str == "front") {
            if (lst.empty())
                cout << "-1"<<"\n";
            else 
                cout << lst.front() << "\n";
        }
        else if (str == "back") {
            if (lst.empty())
                cout << "-1"<<"\n";
            else 
                cout << lst.back() << "\n";
        }
        else if (str == "empty") {
            cout << lst.empty() << "\n";
        }
        else if (str == "size") {
            cout << lst.size() << "\n";
        }
    }
    return 0;
}
