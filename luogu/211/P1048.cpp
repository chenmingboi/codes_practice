#include<bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //0/1背包问题
    int t, m;
    cin >> t >> m;
    vector<int>cost(m+1), value(m+1);
    for(int i = 1;i <= m;i++) {
        cin >> cost[i] >> value[i];
    }
    // //dp[i][j]表示花费时间为j的情况下，对于前i个草药可以踩到的最大总价值
    // vector<vector<int>>dp(m+1, vector<int>(t+1, 0));
    // for(int i = 1;i <= m;i++) {
    //     for(int j = 1;j <= t;j++) {
    //         if(j >= cost[i]) {
    //             //对于草药i，有两种选择不选和选
    //             //不选的话是在前i-1个草药中花费j的时间
    //             //选的话则是要在前i-1个草药中花费j-cost[i]的时间，因为采草药i需要cost[i]的时间
    //             dp[i][j] = max(dp[i-1][j], dp[i-1][j-cost[i]]+value[i]);
    //         } else {
    //             dp[i][j] = dp[i-1][j];
    //         }
    //     }
    // }
    // cout << dp[m][t];
    
    //空间优化
    //dp[i]表示在花费时间i的时候能够采到的草药的最大价值
    //0/1背包第二层要逆向遍历，防止更新的值污染这层正在进行的更新
    vector<int>dp(t+1, 0);
    for(int i = 1;i <= m;i++) {
        for(int j = t;j >= 1;j--) {
            if(j >= cost[i]) {
                dp[j] = max(dp[j], dp[j-cost[i]] + value[i]);
            }
        }
    }
    cout << dp[t];
    return 0;
}