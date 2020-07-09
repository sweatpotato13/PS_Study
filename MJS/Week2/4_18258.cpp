/*
  2. https://www.acmicpc.net/problem/18258
*/

/*
  ������ �����ϴ� ť�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  ����� �� ���� �����̴�.
  
  push X: ���� X�� ť�� �ִ� �����̴�.
  pop: ť���� ���� �տ� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
  size: ť�� ����ִ� ������ ������ ����Ѵ�.
  empty: ť�� ��������� 1, �ƴϸ� 0�� ����Ѵ�.
  front: ť�� ���� �տ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
  back: ť�� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ť�� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

/*
  �Է�
  ù° �ٿ� �־����� ����� �� N (1 �� N �� 2,000,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. 
  �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

  ���
  ����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/
/*
�߰� �� ����
push(element) : ť�� ���Ҹ� �߰�(�ڿ�)
pop() : ť�� �ִ� ���Ҹ� ����(�տ�)
��ȸ
front() : ť ���� �տ� �ִ� ���Ҹ� ��ȯ
back() : ť ���� �ڿ� �ִ� ���Ҹ� ��ȯ
��Ÿ
empty() : ť�� ��������� true �ƴϸ� false�� ��ȯ
size() : ť ����� ��ȯ
*/

#pragma warning(disable:4996)

#include <iostream>
#include <queue>
#include <cstring>
#include <cstdio>

using namespace std;

int main(void) {
    int count;
    string input;
    char cinput[501] = { '\0', };
    queue<int> q;

    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        scanf("%s", cinput);
        input = cinput;

        if (input == "pop") {
            if (q.empty())
                printf("-1\n");
            else {
                printf("%d\n", q.front());
                q.pop();
            }
        }
        else if (input == "size") {
            printf("%d\n", q.size());
        }
        else if (input == "empty") {
            if (q.empty())
                printf("1\n");
            else
                printf("0\n");
        }
        else if (input == "front") {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.front());
        }
        else if (input == "back") {
            if (q.empty())
                printf("-1\n");
            else
                printf("%d\n", q.back());
        }
        else {
            scanf("%s", cinput);
            input = cinput;
            char str[100] = { '\0', };
            strcpy(str, input.c_str());
            q.push(atoi(str));
        }
    }
}