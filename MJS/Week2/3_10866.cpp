/*
  3. https://www.acmicpc.net/problem/10866
*/

/*
  ������ �����ϴ� ��(Deque)�� ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.

  ����� �� ���� �����̴�.
  
  push_front X: ���� X�� ���� �տ� �ִ´�.
  push_back X: ���� X�� ���� �ڿ� �ִ´�.
  pop_front: ���� ���� �տ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
  pop_back: ���� ���� �ڿ� �ִ� ���� ����, �� ���� ����Ѵ�. ����, ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
  size: ���� ����ִ� ������ ������ ����Ѵ�.
  empty: ���� ��������� 1��, �ƴϸ� 0�� ����Ѵ�.
  front: ���� ���� �տ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
  back: ���� ���� �ڿ� �ִ� ������ ����Ѵ�. ���� ���� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
*/

/*
  �Է�
  ù° �ٿ� �־����� ����� �� N (1 �� N �� 10,000)�� �־�����. ��° �ٺ��� N���� �ٿ��� ����� �ϳ��� �־�����. 
  �־����� ������ 1���� ũ�ų� ����, 100,000���� �۰ų� ����. ������ �������� ���� ����� �־����� ���� ����.

  ���
  ����ؾ��ϴ� ����� �־��� ������, �� �ٿ� �ϳ��� ����Ѵ�.
*/


#pragma warning(disable:4996)

#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

int main(void) {
    int count;
    string input;
    deque<int> q;

    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> input;

        if (input == "pop_front") {
            if (q.empty())
                cout << -1 << endl;
            else {
                cout << q.front() << endl;
                q.pop_front();
            }
        }
        else if (input == "pop_back") {
            if (q.empty())
                cout << -1 << endl;
            else {
                cout << q.back() << endl;
                q.pop_back();
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
        else if(input == "push_front"){
            cin >> input;
            char str[100] = { '\0', };
            strcpy(str, input.c_str());
            q.push_front(atoi(str));
        }
        else if (input == "push_back") {
            cin >> input;
            char str[100] = { '\0', };
            strcpy(str, input.c_str());
            q.push_back(atoi(str));
        }
        cin.clear();
    }
}