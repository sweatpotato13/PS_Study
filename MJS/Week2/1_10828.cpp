/*
  1. https://www.acmicpc.net/problem/10828
*/

/*
  ������ �����ϴ� ������ ������ ����, �Է����� �־����� ����� ó���ϴ� ���α׷��� �ۼ��Ͻÿ�.
  
  ����� �� �ټ� �����̴�.
  
  push X: ���� X�� ���ÿ� �ִ� �����̴�.
  pop: ���ÿ��� ���� ���� �ִ� ������ ����, �� ���� ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
  size: ���ÿ� ����ִ� ������ ������ ����Ѵ�.
  empty: ������ ��������� 1, �ƴϸ� 0�� ����Ѵ�.
  top: ������ ���� ���� �ִ� ������ ����Ѵ�. ���� ���ÿ� ����ִ� ������ ���� ��쿡�� -1�� ����Ѵ�.
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
#include <stack>
#include <cstring>

using namespace std;

int main(void) {
    int count;
    string input;
    stack<int> st;

    cin >> count;

    for (int i = 0; i < count; i++) {
        cin >> input;

        if (input == "pop") {
            if (st.empty())
                cout << -1 << endl;
            else {
                cout << st.top() << endl;
                st.pop();
            }
        }
        else if (input == "size") {
            cout << st.size() << endl;
        }
        else if (input == "empty") {
            if (st.empty())
                cout << 1 << endl;
            else
                cout << 0 << endl;
        }
        else if (input == "top") {
            if (st.empty())
                cout << -1 << endl;
            else
                cout << st.top() << endl;
        }
        else {
            cin >> input;
            char str[100] = { '\0', };
            strcpy(str, input.c_str());
            st.push(atoi(str));
        }
        cin.clear();
    }
}