#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    //dp[i][j]表示用了j次传到第i个人的方法
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    //假设小蛮是0号，把圆圈拉成一个序列，第n-1个人右侧为0号
    dp[0][0] = 1;
    //这里的i和j的顺序不能更换，因为第j次的结果依赖于第j-1次的结果所以要把所有人第j-1次的结果都更新出来之后才能更新第j次
    for(int j = 1;j <= m;j++) {
        for(int i = 1;i <= n;i++) {
            dp[i >= n ? i%n : i][j] += dp[i-1][j-1] + dp[(i+1) >= n ? (i+1)%n : i+1][j-1];
        }
    }
    cout << dp[0][m];
    return 0;
}