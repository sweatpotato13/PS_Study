#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/10828
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    stack<int> s;
    int n;
    char cmd[6];
    int x;
    cin >> n;
    for (int i = 0; i < n; i++) {

        scanf("%s", cmd);
        if (!strncmp(cmd, "push", 4)) {
            scanf("%d", &x);
        }

        if (!strncmp(cmd,"push",4)) {
            s.push(x);
        }
        else if (!strncmp(cmd, "pop", 3)) {
            if (s.empty())
                printf("%d\n", -1);
            else {
                printf("%d\n", s.top());
                s.pop();
            }
        }
        else if (!strncmp(cmd, "size", 4)) {
            printf("%d\n", s.size());
        }
        else if (!strncmp(cmd, "empty", 5)) {
            if (s.empty())
                printf("%d\n", 1);
            else {
                printf("%d\n", 0);
            }
        }
        else if (!strncmp(cmd, "top", 3)) {
            if (s.empty())
                printf("%d\n", -1);
            else {
                printf("%d\n", s.top());
            }
        }
    }

    return 0;
}
