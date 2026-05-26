#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, m;
    cin >> t >> m;
    vector<int>cost(m+1), value(m+1);
    for(int i = 1;i <= m;i++) {
        cin >> cost[i] >> value[i];
    }
    vector<long long>dp(t+1, 0);
    for(int i = 1;i <= m;i++) {
        //不是0/b背包而是完全背包，可以重复采
        for(int j = cost[i];j <= t;j++) {
            dp[j] = max(dp[j], dp[j-cost[i]] + value[i]);
        }
    }
    cout << dp[t];
    return 0;
}