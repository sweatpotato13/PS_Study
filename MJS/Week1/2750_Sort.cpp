/*
   2. https://www.acmicpc.net/problem/2750
   �� �����ϱ�
*/

/*
   N���� ���� �־����� ��, �̸� ������������ �����ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

/*
   �Է�
   ù° �ٿ� ���� ���� N(1 �� N �� 1,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ���ڰ� �־�����. �� ���� ������ 1,000���� �۰ų� ���� �����̴�. ���� �ߺ����� �ʴ´�.

   ���
   ù° �ٺ��� N���� �ٿ� ������������ ������ ����� �� �ٿ� �ϳ��� ����Ѵ�.
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