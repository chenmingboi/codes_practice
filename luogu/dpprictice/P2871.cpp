#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>weight(n+1), value(n+1);
    for(int i = 1;i <= n;i++) cin >> weight[i] >> value[i];
    vector<int>dp(m+1, 0);
    for(int i = 1;i <= n;i++) {
        for(int j = m;j >= weight[i];j--) {
            dp[j] = max(dp[j], dp[j-weight[i]] + value[i]);
        }
    }
    cout << dp[m];
    return 0;
}