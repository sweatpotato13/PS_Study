/*
   2. https://www.acmicpc.net/problem/2750
   수 정렬하기
*/

/*
   N개의 수가 주어졌을 때, 이를 오름차순으로 정렬하는 프로그램을 작성하시오.
*/

/*
   입력
   첫째 줄에 수의 개수 N(1 ≤ N ≤ 1,000)이 주어진다. 둘째 줄부터 N개의 줄에는 숫자가 주어진다. 이 수는 절댓값이 1,000보다 작거나 같은 정수이다. 수는 중복되지 않는다.

   출력
   첫째 줄부터 N개의 줄에 오름차순으로 정렬한 결과를 한 줄에 하나씩 출력한다.
*/

#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
	int temp = *b;
	*b = *a;
	*a = temp;
}

int main(void) {
	int index = 0;
	int cnt = 0;
	int* arr;

	scanf("%d", &index);
	if (index < 1 || index > 1000) {
		return 0;
	}
	arr = (int*)malloc(sizeof(int) * index);
	for (int i = 0; i < index; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < index; i++) {
		for (int j = i; j < index; j++) {
			if (arr[i] > arr[j]) {
				swap(&arr[i], &arr[j]);
			}
		}
	}

	for (int i = 0; i < index; i++) {
		printf("%d\n", arr[i]);
	}


	return 0;
}