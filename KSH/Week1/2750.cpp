#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    vector<int> v;
    cin>> n;
    for(int i=0;i<n;i++){
        int e;
        cin >> e;
        v.push_back(e);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++){
        cout << v[i] << "\n";
    }
}