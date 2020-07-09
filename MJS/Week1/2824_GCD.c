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

typedef struct NODE {
	struct map map;
	struct NODE* link;
}NODE;

void InsertA(NODE* head, NODE* tail, NODE* nnode) {
	NODE* before = head;
	NODE* InsertNode = (NODE*)malloc(sizeof(NODE));
	NODE* curr = (NODE*)malloc(sizeof(NODE));
	*InsertNode = *nnode;

	if (head->link == tail) {
		head->link = InsertNode;
		InsertNode->link = tail;
		return;
	}

	curr = head->link;

	while (curr->link != NULL) {
		if (curr->map.factor == InsertNode->map.factor) {
			curr->map.count += InsertNode->map.count;
			return 0;
		}
		curr = curr->link;
	}
	
	curr = head->link;

	while (curr->map.factor < InsertNode->map.factor) {
		before = curr;
		curr = curr->link;
	}

	InsertNode->link = curr;
	before->link = InsertNode;
}

void gcd(NODE* headA, NODE* headB) {
	long long res = 1;
	int isMax = 0;
	NODE* nodeA = headA->link;
	NODE* nodeB = headB->link;

	while (nodeA->link != NULL) {
		while (nodeB->link != NULL) {
			if (nodeA->map.factor == nodeB->map.factor) {
				if (nodeA->map.count > nodeB->map.count) {
					for (int i = 0; i < nodeB->map.count; i++) {
						res *= nodeB->map.factor;
						if (res >= 1000000000) {
							isMax = 1;
							res %= 1000000000;
						}
					}
				}
				else {
					for (int i = 0; i < nodeA->map.count; i++) {
						res *= nodeA->map.factor;
						if (res >= 1000000000) {
							isMax = 1;
							res %= 1000000000;
						}
					}
				}
			}
			nodeB = nodeB->link;
		}
		nodeB = headB->link;
		nodeA = nodeA->link;
	}

	if (isMax) {
		printf("%09d", res);
	}
	else {
		printf("%d", res);
	}
}

int main(void) {
	int num1 = 0, num2 = 0;
	int tempNum = 0;
	//int result = 1;
	long long* resnum1 = NULL;
	long long* resnum2 = NULL;
	int isMax = 0;
	NODE* headA;
	NODE* tailA;
	NODE* headB;
	NODE* tailB;
	NODE* nnode;
	headA = (NODE*)malloc(sizeof(NODE));
	tailA = (NODE*)malloc(sizeof(NODE));
	headB = (NODE*)malloc(sizeof(NODE));
	tailB = (NODE*)malloc(sizeof(NODE));
	nnode = (NODE*)malloc(sizeof(NODE));
	headA->link = tailA;
	tailA->link = NULL;
	headB->link = tailB;
	tailB->link = NULL;

	scanf("%d", &num1);
	if ((num1 < 1) || (num1 > 1000)) {
		return 0;
	}
	resnum1 = (long long*)malloc(sizeof(long long) * num1);

	for (int i = 0; i < num1; i++) {
		scanf("%d", &tempNum);
		if (tempNum >= 1000000000) {
			return 0;
		}
		resnum1[i] = tempNum;
		for (int j = 2; j <= resnum1[i]; j++) {
			nnode->map.factor = j;
			nnode->map.count = 0;
			while (resnum1[i] % j == 0) {
				resnum1[i] /= j;
				nnode->map.count++;
			}
			if (nnode->map.count != 0) {
				InsertA(headA, tailA, nnode);
			}
		}
	}

	scanf("%d", &num2);
	if ((num2 < 1) || (num2 > 1000)) {
		return 0;
	}
	resnum2 = (long long*)malloc(sizeof(long long) * num2);

	for (int i = 0; i < num2; i++) {
		scanf("%d", &tempNum);
		if (tempNum >= 1000000000) {
			return 0;
		}
		resnum2[i] = tempNum;
		for (int j = 2; j <= resnum2[i]; j++) {
			nnode->map.factor = j;
			nnode->map.count = 0;
			while (resnum2[i] % j == 0) {
				resnum2[i] /= j;
				nnode->map.count++;
			}
			if (nnode->map.count != 0) {
				InsertA(headB, tailB, nnode);
			}
		}
	}
	
	free(resnum1);
	free(resnum2);
	free(nnode);

	gcd(headA, headB);


	free(headA);
	free(tailA);
	free(headB);
	free(tailB);

	return 0;
}