#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
using namespace std;
vector<string> nve;
vector<string> mve;
map <string, int> hmve;

int main(void) {
	ios_base::sync_with_stdio(false);
	int n = 0, m = 0, ans = 0;
	string s;
	cin >> n ;
	cin >> m;
	
	for(int i=0;i<n;i++) {
		cin >> s;
		nve.push_back(s);
	}
	for(int i=0;i<m;i++){
		cin >> s;
		hmve[s]++;
	}

	for(int i=0;i<n;i++) {
		ans = ans + hmve[nve.at(i)];
	}
	cout << ans << endl;
	system("pause");
	return 0;
}