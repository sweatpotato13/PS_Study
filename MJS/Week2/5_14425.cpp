/*
  5. https://www.acmicpc.net/problem/14425
*/

/*
  �� N���� ���ڿ��� �̷���� ���� S�� �־�����.

  �Է����� �־����� M���� ���ڿ� �߿��� ���� S�� ���ԵǾ� �ִ� ���� �� �� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.
*/

/*
  �Է�
  ù° �ٿ� ���ڿ��� ���� N�� M (1 �� N �� 10,000, 1 �� M �� 10,000)�� �־�����.
  ���� N���� �ٿ��� ���� S�� ���ԵǾ� �ִ� ���ڿ����� �־�����.
  ���� M���� �ٿ��� �˻��ؾ� �ϴ� ���ڿ����� �־�����.
  �Է����� �־����� ���ڿ��� ���ĺ� �ҹ��ڷθ� �̷���� ������, ���̴� 500�� ���� �ʴ´�.
  ���� S�� ���� ���ڿ��� ���� �� �־����� ���� ����.

  ���
  ù° �ٿ� M���� ���ڿ� �߿� �� �� ���� ���� S�� ���ԵǾ� �ִ��� ����Ѵ�.
*/


#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
#include <cstdio>
#include <map>

using namespace std;

int main(void) {
	int n = 0;
	int m = 0;
	int count = 0;
	string input;
	char temp[501];
	map< string, int > mapA;

	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%s", temp);
		input = temp;
		mapA.insert(make_pair(input, 0));
	}

	for (int i = 0; i < m; i++) {
		scanf("%s", temp);
		input = temp;
		if (mapA.find(input) == mapA.end()) {

		}
		else {
			count++;
		}
	}

	printf("%d", count);
}