/*
  4. https://www.acmicpc.net/problem/3273
*/

#pragma warning(disable:4996)

#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>

using namespace std;

int main(void) {
    int count = 0;
    int res = 0;
    int temp = 0;
    int total = 0;
    vector<int> v;

    scanf("%d", &count);

    for (int j = 0; j < count; j++) {
        scanf("%d", &temp);
        v.push_back(temp);
    }

    scanf("%d", &res);

    for (int i = 0; i < count; i++) {
        if (v[i] > res)
            continue;
        if (find(v.begin()+(i+1), v.end(), (res - v[i])) != v.end())
            total++;
    }

    printf("%d", total);

    return 0;
}