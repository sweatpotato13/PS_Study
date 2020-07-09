/*
   4. https://www.acmicpc.net/problem/2504
   ��ȣ�� ��
*/

/*
   4���� ��ȣ ��(��, ��)��, ��[��, ��]���� �̿��ؼ� ��������� ��ȣ�� �߿��� �ùٸ� ��ȣ���̶� ������ ���� ���ǵȴ�.

   �� ���� ��ȣ�θ� �̷���� ��()���� ��[]���� �ùٸ� ��ȣ���̴�.
   ���� X�� �ùٸ� ��ȣ���̸� ��(X)���̳� ��[X]���� ��� �ùٸ� ��ȣ���� �ȴ�.
   X�� Y ��� �ùٸ� ��ȣ���̶�� �̵��� ������ XY�� �ùٸ� ��ȣ���� �ȴ�.
   ���� ��� ��(()[[]])���� ��(())[][]�� �� �ùٸ� ��ȣ�������� ��([)]�� �� ��(()()[]�� �� ��� �ùٸ� ��ȣ���� �ƴϴ�. �츮�� � �ùٸ� ��ȣ�� X�� ���Ͽ� �� ��ȣ���� ��(��ȣ��)�� �Ʒ��� ���� �����ϰ� ��(X)�� ǥ���Ѵ�.

   ��()�� �� ��ȣ���� ���� 2�̴�.
   ��[]�� �� ��ȣ���� ���� 3�̴�.
   ��(X)�� �� ��ȣ���� 2����(X) ���� ���ȴ�.
   ��[X]�� �� ��ȣ���� 3����(X) ���� ���ȴ�.
   �ùٸ� ��ȣ�� X�� Y�� ���յ� XY�� ��ȣ���� ��(XY)= ��(X)+��(Y) �� ���ȴ�.
   ���� ��� ��(()[[]])([])�� �� ��ȣ���� ���غ���.  ��()[[]]�� �� ��ȣ���� 2 + 3��3=11 �̹Ƿ�  ��(()[[ ]])���� ��ȣ���� 2��11=22 �̴�. �׸���  ��([])���� ���� 2��3=6 �̹Ƿ� ��ü ��ȣ���� ���� 22 + 6 = 28 �̴�.

   �������� Ǯ��� �� ������ �־��� ��ȣ���� �а� �� ��ȣ���� �տ��� �����Ѵ�� ����Ͽ� ����ϴ� ���̴�.
*/

/*
   �Է�
   ù° �ٿ� ��ȣ���� ��Ÿ���� ���ڿ�(��Ʈ��)�� �־�����. �� �� ���̴� 1 �̻�, 30 �����̴�.

   ���
   ù° �ٿ� �� ��ȣ���� ���� ��Ÿ���� ������ ����Ѵ�. ���� �Է��� �ùٸ��� ���� ��ȣ���̸� �ݵ�� 0�� ����ؾ� �Ѵ�.
*/

#pragma warning(disable:4996)

#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

int main(void) {
	char str[31] = { '\0', };
	int cnt = 0;
	int sum = 0;
	int preSize = 0;
	stack<int> st;
	stack<int> sta;
	stack<int> num;

	cin >> str;

	if (strlen(str) % 2 != 0 || strlen(str)>30) {
		cout << 0;
		return 0;
	}

	if (str[strlen(str) - 1] == '(' || str[strlen(str) - 1] == '[') {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < strlen(str); i++) {
		sta.push(str[cnt++]);
		if ((char)sta.top() != '[' && (char)sta.top() != ']'
			&& (char)sta.top() != '(' && (char)sta.top() != ')') {
			cout << 0;
			return 0;
		}

		if (cnt - 1 == 0) {
			if (sta.top() == ')' || sta.top() == ']') {
				cout << 0;
				return 0;
			}
			if (sta.top() != '[' && sta.top() != ']'
				&& sta.top() != '(' && sta.top() != ')') {
				cout << 0;
				return 0;
			}
		}

		if (sta.top() == ']') {
			sta.pop();
			if (!(sta.empty())) {
				if (sta.top() != '[') {
					cout << 0;
					return 0;
				}
				else {
					sta.pop();
				}
			}
			else {
				cout << 0;
				return 0;
			}
		}
		else if (sta.top() == ')') {
			sta.pop();
			if (!(sta.empty())) {
				if (sta.top() != '(') {
					cout << 0;
					return 0;
				}
				else {
					sta.pop();
				}
			}
			else {
				cout << 0;
				return 0;
			}
		}
	}

	for (int i = 0; i < strlen(str); i++) {
		st.push(str[i]);
		if (!st.empty()) {
			if (st.top() == ']') {
				st.pop();
				if (!(st.empty())) {
					if (st.top() == '[') {
						st.pop();
						if (st.size() == 0) {
							int tempS = 0;
							while (!num.empty()) {
								printf("num.top: %d\n", num.top());
								tempS += num.top();
								num.pop();
							}
							if (tempS == 0) {
								sum += 3;
							}
							else {
								printf("tempS: %d\n", tempS);
								sum += tempS * 3;
							}
							printf("%d\n", sum);
							continue;
						}
						if (st.size() > preSize) {
							num.push(3);
							preSize = st.size();
						}
						else if (st.size() < preSize) {
							if (!num.empty()) {
								int tempN = num.top() * 3;
								num.pop();
								num.push(tempN);
							}
							else {
								num.push(3);
							}
							preSize = st.size();

						}
						else {
							num.push(3);
							preSize = st.size();

						}
					}
					else {
						cout << 0;
						return 0;
					}
				}
			}
			else if (st.top() == ')') {
				st.pop();
				if (!(st.empty())) {
					if (st.top() == '(') {
						st.pop();
						if (st.size() == 0) {
							int tempS = 0;
							while (!num.empty()) {
								printf("num.top: %d\n", num.top());
								tempS += num.top();
								num.pop();
							}
							if (tempS == 0) {
								sum += 2;
							}
							else {
								printf("tempS: %d\n", tempS);
								sum += tempS * 2;
							}
							printf("%d\n", sum);
							continue;
						}
						if (st.size() > preSize) {
							num.push(2);
							preSize = st.size();

						}
						else if(st.size()< preSize) {
							if (!num.empty()) {
								int tempN = num.top() * 2;
								num.pop();
								num.push(tempN);

							}
							else {
								num.push(2);
							}
							preSize = st.size();

						}
						else {
							num.push(2);
							preSize = st.size();

						}
					}
					else {
						cout << 0;
						return 0;
					}
				}
			}
		}
	}
	if (!num.empty()) {
		cout<<"exist";
	}
	cout << sum;

	return 0;
}