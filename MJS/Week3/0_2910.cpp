/*
  0. https://www.acmicpc.net/problem/2910
*/

#pragma warning(disable:4996)

#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
using namespace std;

typedef struct info {
	int num;
	int count;
	int order;
}info;

bool cmp(const info& a, const info& b)
{
	if (a.count > b.count) return true; 
	else if (a.count == b.count) 
	{
		if (a.order < b.order) return true; 
		else if (a.order == b.order) 
		{
			if (a.num < b.num) return true; 
		}
	}

	return false;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);// cin, scanf 동시 사용 x 
	int n = 0;
	int m = 0;
	int temp;
	vector<info> v;
	vector<int> chk;
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &temp);
		if (temp > m)
			return 0; 
		auto iter = find(chk.begin(), chk.end(), temp);
		if (iter != chk.end()) {
			auto iter = std::find_if(v.begin(), v.end(),
				[&](info const& k) {return k.num == temp; });
			if (iter != v.end())
				iter->count++;
		}
		else {
			v.push_back({temp,1,i});
			chk.push_back(temp);
		}
	}

	std::sort(v.begin(), v.end(), cmp);

	for (auto i : v) {
		for (int j = 0; j < i.count; j++)
			printf("%d ", i.num);
	}

	return 0;
}