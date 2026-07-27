#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    //dp[i][j]表示已经放了i个算筹，其中红色比黑色多j个的方案数
    vector<vector<int>>dp(2*n+1, vector<int>(n+1, 0));
    dp[0][0] = 1;
    for(int i = 0;i < 2*n;i++) {
        for(int j = 0;j <= n;j++) {
            //红色最多比黑色多n个，因为总共2*n个且红黑要相等红色最多为n个
            //放红色
            if(j+1 <= n) {
                dp[i+1][j+1] = (dp[i+1][j+1] + dp[i][j]) % 100;
            }
            //放黑色，只有j>0的时候才可以放黑色，保证前i个元素中红色元素>=黑色元素
            if(j > 0) {
                dp[i+1][j-1] = (dp[i+1][j-1] + dp[i][j]) % 100;
            }
        }
    }
    cout << dp[2*n][0];
    return 0;
}