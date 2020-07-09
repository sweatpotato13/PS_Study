/*
  2. https://www.acmicpc.net/problem/10845
*/

/*
  정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령을 처리하는 프로그램을 작성하시오.

  명령은 총 여섯 가지이다.

  push X: 정수 X를 큐에 넣는 연산이다.
  pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
  size: 큐에 들어있는 정수의 개수를 출력한다.
  empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
  front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
  back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

/*
  입력
  첫째 줄에 주어지는 명령의 수 N (1 ≤ N ≤ 10,000)이 주어진다. 둘째 줄부터 N개의 줄에는 명령이 하나씩 주어진다. 
  주어지는 정수는 1보다 크거나 같고, 100,000보다 작거나 같다. 문제에 나와있지 않은 명령이 주어지는 경우는 없다.

  출력
  출력해야하는 명령이 주어질 때마다, 한 줄에 하나씩 출력한다.
*/
/*
추가 및 삭제
push(element) : 큐에 원소를 추가(뒤에)
pop() : 큐에 있는 원소를 삭제(앞에)
조회
front() : 큐 제일 앞에 있는 원소를 반환
back() : 큐 제일 뒤에 있는 원소를 반환
기타
empty() : 큐가 비어있으면 true 아니면 false를 반환
size() : 큐 사이즈를 반환
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