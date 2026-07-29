#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>m(n+1), pre(n+1, 0);
    for(int i = 1;i <= n;i++) cin >> m[i];
    //求前缀和
    for(int i = 1;i <= n;i++) pre[i] = pre[i-1] + m[i];
    //dp[i][j]表示合并[i, j]区间堆的最小代价
    vector<vector<int>>dp(n+1, vector<int>(n+1, INF));
    for(int i = 1;i <= n;i++) dp[i][i] = 0;
    //最外层枚举区间长度, 因为长区间的dp依赖于更新好的短区间的dp所以要先枚举len
    for(int len = 2;len <= n;len++) {
        //枚举区间左端点
        for(int i = 1;i+len-1 <= n;i++) {
            //右端点位置
            int j = i + len - 1;
            int cost = pre[j] - pre[i-1];
            //枚举中间断点，把区间分成[i, k]和[k+1, j]
            for(int k = i;k < j;k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k+1][j] + cost);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}