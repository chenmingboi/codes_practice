#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, v;
    cin >> n >> v;
    vector<int>cost(n), value(n), cnt(n);
    for(int i = 0;i < n;i++) cin >> cost[i] >> value[i] >> cnt[i];
    vector<int>dp(v+1, 0);
    for(int i = 0;i < n;i++) {
        for(int j = v;j >= 0;j--) {
            //第i种物品选择k件
            for(int k = 0;k <= cnt[i];k++) {
                if(j >= k*cost[i]) {
                    dp[j] = max(dp[j], dp[j-k*cost[i]] + k*value[i]);
                }
            }
        }
    }
    cout << dp[v];
    return 0;
}