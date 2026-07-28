#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<int>cost(n+1),value(n+1);
    for(int i = 0;i < n;i++) {
        cin >> value[i] >> cost[i];
    }
    vector<int>dp(m+1, 0);
    //完全背包
    for(int i = 0;i < n;i++) {
        for(int j = cost[i];j <= m;j++) {
            dp[j] = max(dp[j], dp[j-cost[i]] + value[i]);
        }
    }
    cout << dp[m];
    return 0;
}
