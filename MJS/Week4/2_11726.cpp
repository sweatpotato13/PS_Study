/*
  2. https://www.acmicpc.net/problem/11726
*/

#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int main(void) {
    cin.tie(nullptr);
    int input = 0;
    int* arr = new int[1001];
    
    scanf("%d", &input);

    arr[1] = 1;
    arr[2] = 2;

    for (int i = 3; i < 1001; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2]) % 10007;
    }

    printf("%d", arr[input]);

    return 0;
}