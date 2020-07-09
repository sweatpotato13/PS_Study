/*
   5. https://www.acmicpc.net/problem/2824
   �ִ�����
*/

/*
   ����̴� �л��鿡�� �� ���� ���� A�� B�� �ִ������� ����ϴ� ������ ���־���. �׷���, ����̴� �л����� �������̱� ���� �ſ� ū A�� B�� �־���.
   ����̴� N���� ���� M���� ���� �־���, N���� ���� ��� ���ϸ� A, M���� ���� ��� ���ϸ� B�� �ȴ�.
   �� ���� �־����� ��, �ִ������� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

/*
   �Է�
   ù° �ٿ� N�� �־�����.(1 �� N �� 1000) ��° �ٿ��� N���� ������ �������� ���еǾ� �־�����. �� ���� ��� 1,000,000,000���� �۰�, N���� ���� ���ϸ� A�� �ȴ�.
   ��° �ٿ� M�� �־�����.(1 �� M �� 1000) ��° �ٿ��� M���� ������ �������� ���еǾ� �־�����. �� ���� ��� 1,000,000,000���� �۰�, M���� ���� ���ϸ� B�� �ȴ�.

   ���
   �� ���� �ִ������� ����Ѵ�. ����, 9�ڸ����� ��ٸ�, ������ 9�ڸ��� ����Ѵ�. (�ִ� ������� 1000012028�� ��쿡�� 000012028�� ����ؾ� �Ѵ�)
*/

#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct map {
	int factor;
	int count;
}map;

int main(void) {
	int sieve[40000] = { 0, };
	int num1 = 0, num2 = 0;
	int sizeA = 1;
	int sizeB = 1;
	int tempNum = 0;
	int isMax = 0;
	long long res = 1;
	map mapA[40000];
	map mapB[40000];
	map* mapR;
	map* mapRS;
	mapR = (map*)malloc(sizeof(map));
	mapRS = (map*)malloc(sizeof(map));
	scanf("%d", &num1);

	for (int i = 0; i < 40000; i++) {
		if (i >= 2)
			sieve[i] = 1;
		mapA[i].count = 0;
		mapB[i].count = 0;
	}

	for (int i = 2; i <= 40000; i++) {
		if (sieve[i] == 1) {
			for (int j = i + i; j < 40000; j += i) {
				sieve[j] = 0;
			}
		}
		else continue;
	}

	//�������� �������ִ� map �����~

	for (int i = 0; i < num1; i++) {
		scanf("%d", &tempNum);
		for (int j = 2; j < 40000; j++) {
			if (sieve[j] == 1) {
				if (tempNum % j == 0) {
					int count = 0;

					while (tempNum % j == 0) {
						tempNum /= j;
						count++;
					}

					mapA[j].count += count;
				}
			}
		}
		if (tempNum != 1) {
			int isExist = 0;
			for (int l = 0; l < sizeA; l++) {
				if (mapR[l].factor == tempNum) {
					mapR[l].count++;
					isExist = 1;
					break;
				}
			}
			if (isExist != 1) {
				mapR = (map*)realloc(mapR, sizeof(map) * (++sizeA));
				mapR[sizeA - 1].factor = tempNum;
				mapR[sizeA - 1].count = 1;
			}
		}
	}

	scanf("%d", &num2);

	for (int i = 0; i < num2; i++) {
		scanf("%d", &tempNum);
		for (int j = 2; j < 40000; j++) {
			if (sieve[j] == 1) {
				if (tempNum % j == 0) {
					int count = 0;

					while (tempNum % j == 0) {
						tempNum /= j;
						count++;
					}

					mapB[j].count += count;
				}
			}
		}
		if (tempNum != 1) {
			int isExist = 0;
			for (int l = 0; l < sizeA; l++) {
				if (mapRS[l].factor == tempNum) {
					mapRS[l].count++;
					isExist = 1;
					break;
				}
			}
			if (isExist != 1) {
				mapRS = (map*)realloc(mapRS, sizeof(map) * (++sizeB));
				mapRS[sizeB - 1].factor = tempNum;
				mapRS[sizeB - 1].count = 1;
			}
		}
	}

	for (int i = 0; i < 40000; i++) {
		if (mapA[i].count != 0 && mapB[i].count != 0) {
			if (mapA[i].count > mapB[i].count) {
				for (int k = 0; k < mapB[i].count; k++) {
					res *= i;
					if (res > 999999999) {
						isMax = 1;
						res %= 1000000000;
					}
				}
			}
			else {
				for (int k = 0; k < mapA[i].count; k++) {
					res *= i;
					if (res > 999999999) {
						isMax = 1;
						res %= 1000000000;
					}
				}
			}
		}
	}

	for (int i = 0; i < sizeA; i++) {
		for (int j = 0; j < sizeB; j++) {
			if (mapR[i].factor == mapRS[j].factor) {
				if (mapR[i].count > mapRS[j].count) {
					for (int k = 0; k < mapRS[j].count; k++) {
						res *= mapRS[j].factor;
						if (res > 999999999) {
							isMax = 1;
							res %= 1000000000;
						}
					}
				}
				else {
					for (int k = 0; k < mapR[i].count; k++) {
						res *= mapR[i].factor;
						if (res > 999999999) {
							isMax = 1;
							res %= 1000000000;
						}
					}
				}
				break;
			}
		}
	}

	if (isMax) {
		printf("%09lld", res);
	}
	else {
		printf("%lld", res);
	}

	return 0;
}