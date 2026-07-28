#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v;
    cin >> n >> v;
    vector<int>cost(n), value(n);
    for(int i = 0;i < n;i++) cin >> cost[i] >> value[i];
    vector<int>dp(v+1,0);
    for(int i = 0;i < n;i++) {
        //完全背包正序遍历
        for(int j = cost[i];j <= v;j++) {
            dp[j] = max(dp[j], dp[j-cost[i]] + value[i]);
        }
    }
    cout << dp[v];
    return 0;
}