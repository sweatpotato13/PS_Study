/*
  2. https://www.acmicpc.net/problem/10845
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
  ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. 
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

using namespace std;

int main(void) {
    int count;
    string input;
    queue<int> q;

    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> input;
        
        if (input == "pop") {
            if (q.empty())
                cout << -1 << endl;
            else {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (input == "size") {
            cout << q.size() << endl;
        }
        else if (input == "empty") {
            if (q.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (input == "front") {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.front() << endl;
        }
        else if (input == "back") {
            if (q.empty())
                cout << -1 << endl;
            else
                cout << q.back() << endl;
        }
        else {
            cin >> input;
            char str[100] = { '\0', };
            strcpy(str, input.c_str());
            q.push(atoi(str));
        }
        cin.clear();
    }
}