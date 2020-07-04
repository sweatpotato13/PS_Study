#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;
stack <char> sta;
int main(void) {
	char c;
	string s;
	int i = 0;
	int tem = 1, ans = 0;
	cin >> s;
	 for(int i=0;i<s.size();i++){
		
		 c = s.at(i);
		
		if (c == '(') {
			tem = tem * 2; 
			sta.push(c);
		}
		if (c == '[') {
			tem = tem * 3;
			sta.push(c);
		}
		if (c == ')') {
			if (sta.size() == 0) {
				ans = 0;
				cout << ans << endl;
				return 0;
			}
			if (sta.top() == '(') {
				if (s.at(i - 1) == '(') {
					ans = ans + tem;
				}				
				tem = tem / 2;
				sta.pop();
			}
			else
			{
				ans = 0;
				cout << ans << endl;
				return 0;
			}
		}
		if (c == ']') {
			if (sta.size() == 0) {
				ans = 0;
				cout << ans << endl;
				return 0;
			}
			if (sta.top() == '[') {
				if (s.at(i - 1) == '[') {
					ans = ans + tem;
				}
				tem = tem / 3;
				sta.pop();
			}
			else
			{
				ans = 0;
				cout << ans << endl;
				return 0;
			}
		}

	 }
	 if (sta.size() != 0) {
		 ans = 0;
		 cout << ans << endl;
		 return 0; 
	 }
	cout << ans<<endl;
	
	return 0;

}