#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>xuehao(n);
    for(int i = 0;i < n;i++) {
        cin >> xuehao[i];
    }
    for(int i = 0;i < m;i++) {
        int que;
        cin >> que;
        cout << xuehao[que-1] << endl;
    }
    return 0;
}