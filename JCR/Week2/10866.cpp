#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/10866
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    list<int> l;
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        if(!s.compare("push_front")){
            int e;
            cin >> e;
            l.push_front(e);
        }
        else if(!s.compare("push_back")){
            int e;
            cin >> e;
            l.push_back(e);
        }
        else if(!s.compare("pop_front")){
            int e;
            if(l.empty())
                e = -1;
            else{
                e = l.front();
                l.pop_front();
            }
                cout << e << "\n";
        }
        else if(!s.compare("pop_back")){
            int e;
            if(l.empty())
                e = -1;
            else{
                e = l.back();
                l.pop_back();
            }
                cout << e << "\n";
        }
        else if(!s.compare("size")){
            int e = l.size();
            cout << e << "\n";
        }
        else if(!s.compare("empty")){
            int e = l.empty();
            cout << e << "\n";
        }
        else if(!s.compare("front")){
            int e;
            if(l.empty())
                e = -1;
            else
                e = l.front();

            cout << e << "\n";
        }
        else if(!s.compare("back")){
            int e;
            if(l.empty())
                e = -1;
            else
                e = l.back();

            cout << e << "\n";
        }
    }

    return 0;

}
