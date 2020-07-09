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