#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>v(n+1);
    for(int i = 1;i <= n;i++) cin >> v[i];
    //dp[i][j]表示的是从i到j的所有物品最多可以卖出多少钱
    //计算的时候除了[i,j]范围内的物品其他物品都已经卖光了
    //所以要乘对应的天数
    vector<vector<int>>dp(n+1, vector<int>(n+1));
    dp[0][0] = 0;
    //dp[i][i]表示的是除了第i个物品其他物品都已经卖光了
    //那么第i个物品所能卖出的价钱就是v[i]*n
    for(int i = 1;i <= n;i++) dp[i][i] = n*v[i];
    //这里得先把短范围得给卖完了才能更新长范围的
    //不能单纯的i,j遍历j>=i这样更新的是dp[n][n]而不是dp[1][n]
    for(int len = 2;len <= n;len++) {
        for(int i = 1;i+len-1 <= n;i++) {
            int j = i+len-1;
            dp[i][j] = max(dp[i+1][j] + (n-len+1)*v[i], dp[i][j-1] + (n-len+1)*v[j]);
        }
    }
    cout << dp[1][n];
    return 0;
}