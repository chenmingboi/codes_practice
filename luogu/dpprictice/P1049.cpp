#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, n;
    cin >> v >> n;
    vector<int>tiji(n);
    for(int i = 0;i < n;i++) cin >> tiji[i];
    //dp[i]表示体积v的箱子最多装多少体积的物品
    vector<int>dp(v+1, 0);
    // 0/1背包问题
    for(int i = 0;i < n;i++) {
        for(int j = v;j >= tiji[i];j--) {
            dp[j] = max(dp[j], dp[j-tiji[i]] + tiji[i]);
        }
    }
    cout << v - dp[v];
    return 0;
}