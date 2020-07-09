/*
   5. https://www.acmicpc.net/problem/2824
   최대공약수
*/

/*
   상근이는 학생들에게 두 양의 정수 A와 B의 최대공약수를 계산하는 문제를 내주었다. 그런데, 상근이는 학생들을 골탕먹이기 위해 매우 큰 A와 B를 주었다.
   상근이는 N개의 수와 M개의 수를 주었고, N개의 수를 모두 곱하면 A, M개의 수를 모두 곱하면 B가 된다.
   이 수가 주어졌을 때, 최대공약수를 구하는 프로그램을 작성하시오.
*/

/*
   입력
   첫째 줄에 N이 주어진다.(1 ≤ N ≤ 1000) 둘째 줄에는 N개의 정수가 공백으로 구분되어 주어진다. 이 수는 모두 1,000,000,000보다 작고, N개의 수를 곱하면 A가 된다.
   셋째 줄에 M이 주어진다.(1 ≤ M ≤ 1000) 넷째 줄에는 M개의 정수가 공백으로 구분되어 주어진다. 이 수는 모두 1,000,000,000보다 작고, M개의 수를 곱하면 B가 된다.

   출력
   두 수의 최대공약수를 출력한다. 만약, 9자리보다 길다면, 마지막 9자리만 출력한다. (최대 공약수가 1000012028인 경우에는 000012028을 출력해야 한다)
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

	//나머지를 저장해주는 map 만들기~

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