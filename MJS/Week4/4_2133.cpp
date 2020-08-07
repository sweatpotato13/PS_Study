/*
  4. https://www.acmicpc.net/problem/2133
*/

#pragma warning(disable:4996)

#include <iostream>

using namespace std;

int main(void) {
	cin.tie(nullptr);
	int input = 0;
	int* arr = new int[31];

	scanf("%d", &input);

	if (input % 2 != 0)
		printf("0\n");
	else {
		arr[0] = 1;
		for (int i = 2; i <= 31; i += 2) {
			arr[i] = arr[i - 2];
			for (int j = 2; j <= i; j += 2) {
				arr[i] += (2*arr[i-j]);
			}
		}
		printf("%d\n", arr[input]);
	}

	return 0;
}