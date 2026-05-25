#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r;
    cin >> r;
    vector<vector<int>>num(r), dp(r, vector<int>(r));
    for(int i = 0;i < r;i++) {
        for(int j = 0;j <= i;j++) {
            int n;
            cin >> n;
            num[i].push_back(n);
        }
    }
    dp[0][0] = num[0][0];
    //最左侧的数字只能由上方的数字来
    for(int i = 1;i < r;i++) {
        dp[i][0] = dp[i-1][0] + num[i][0];
    }
    //最右侧的数字只能由左上方的数字来
    for(int i = 1;i < r;i++) {
        dp[i][i] = dp[i-1][i-1] + num[i][i];
    }
    //中间部分的数字可以由上方数字来，也可以由左上方的数字来
    for(int i = 1;i < r;i++) {
        for(int j = 1;j < i;j++) {
            dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + num[i][j];
        }
    }
    int ans = 0;
    for(int i = 0;i < r;i++) {
        ans = max(ans, dp[r-1][i]);
    }
    cout << ans;
    return 0;
}