#include <bits/stdc++.h>
using namespace std;
stack<int>lst;
 
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (str == "push") {
            int x; 
            cin >> x;
            lst.push(x);
        }
        else if (str == "top") {
            if (lst.empty())
                cout << "-1"<<"\n";
            else 
                cout << lst.top() << "\n";
        }
        else if (str == "pop") {
            if (lst.empty())
                cout << "-1" << "\n";
            else {
                cout << lst.top() << "\n";
                lst.pop();
            }
        }
        else if (str == "empty") {
            cout << lst.empty() << "\n";
        }
        else {
            cout << lst.size() << "\n";
        }
    }
    return 0;
}

