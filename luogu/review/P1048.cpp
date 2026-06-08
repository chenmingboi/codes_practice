#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, m;
    cin >> t >> m;
    vector<int>cost(m+1), value(m+1), dp(t+1);
    for(int i = 1;i <= m;i++) {
        cin >> cost[i] >> value[i];
    }
    dp[0] = 0;
    // 0/1背包问题
    for(int i = 1;i <= m;i++) {
        for(int j = t;j >= cost[i];j--) {
            dp[j] = max(dp[j], dp[j-cost[i]] + value[i]);
        }
    }
    cout << dp[t];
    return 0;
}