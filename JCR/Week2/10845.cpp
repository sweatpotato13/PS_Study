#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/10845
int main(){
    //ios::sync_with_stdio(false);
    //cin.tie(nullptr);
    queue<int> q;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        char cmd[6];
        scanf("%s", cmd);
        if (!strcmp(cmd, "push")) {
            int x;
            scanf("%d", &x);
            q.push(x);
        }
        else if (!strcmp(cmd, "pop")) {
            if (q.empty())
                printf("-1\n");
            else {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (!strcmp(cmd, "size")) {
            printf("%d\n", q.size());
        }
        else if (!strcmp(cmd, "empty")) {
            printf("%d\n", q.empty());
        }
        else if (!strcmp(cmd, "front")) {
            if (q.empty())
                printf("-1\n");
            else {
                printf("%d\n", q.front());
            }
        }
        else if (!strcmp(cmd, "back")) {
            if (q.empty())
                printf("-1\n");
            else {
                printf("%d\n", q.back());
            }
        }
    }

    return 0;

}
