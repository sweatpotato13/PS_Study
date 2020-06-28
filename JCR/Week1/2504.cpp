#pragma warning(disable : 4996)
#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define dup(x) x.erase(unique(x.begin(), x.end()),x.end())
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
// https://www.acmicpc.net/problem/2504
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> str;
    ll temp = 1;
    ll res = 0;
    stack<char> st;
	for(int i =0;i<str.length();i++){
		if(str[i] == '('){
			temp *= 2;
			st.push('(');
		}
		if(str[i] == '['){
			temp *= 3;
			st.push('[');
		}
		if(str[i] == ')' && st.empty()){
			res = 0;
			break;
		}
		if(str[i] == ']' && st.empty()){
			res = 0;
			break;
		}
		if(str[i] == ')' && !st.empty()){
			if(st.top() == '('){
				if(str[i-1] == '('){
					res += temp;
				}
				temp /= 2;
				st.pop();
			}
			else{
				res = 0;
				break;
			}
		}
		if(str[i] == ']' && !st.empty()){
			if(st.top() == '['){
				if(str[i-1] == '['){
					res += temp;
				}
				temp /= 3;
				st.pop();
			}	
			else{
				res = 0;
				break;
			}	
		}
	}
	if(!st.empty())
		res = 0;
    cout << res;

	return 0;
}