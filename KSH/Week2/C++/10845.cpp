#include <bits/stdc++.h>
using namespace std;
queue<int>lst;
 
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
        else if (str == "pop") {
            if (lst.empty())
                cout << "-1" << "\n";
            else {
                cout << lst.front() << "\n";
                lst.pop();
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
