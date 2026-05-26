#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //0/1背包
    int n, m;
    cin >> n >> m;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    //dp[i]表示花费i元钱的点菜方案
    vector<int>dp(m+1, 0);
    dp[0] = 1;//花费0元钱只有一种方案就是不点
    for(int i = 1;i <= n;i++) {
        for(int j = m;j >= a[i];j--) {
            dp[j] = dp[j] + dp[j-a[i]];
        }
    }
    cout << dp[m];
    return 0;
}