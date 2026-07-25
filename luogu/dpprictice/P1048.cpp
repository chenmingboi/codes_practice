#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, m;
    cin >> t >> m;
    vector<int>value(m);
    vector<int>cost(m);
    for(int i = 0;i < m;i++) cin >> cost[i] >> value[i];
    vector<int>dp(t+1, 0);
    for(int i = 0;i < m;i++) {
        for(int j = t;j >= cost[i];j--) {
            dp[j] = max(dp[j], dp[j-cost[i]] + value[i]);
        }
    }
    cout << dp[t];
    return 0;
}