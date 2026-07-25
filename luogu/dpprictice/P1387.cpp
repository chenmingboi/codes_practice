#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>mp(n+1, vector<int>(m+1));
    //dp[i][j]表示以i,j为右下角的最大全1正方形的边长
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cin >> mp[i][j];
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(mp[i][j] == 0) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = min({dp[i-1][j-1], dp[i-1][j], dp[i][j-1]}) + 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans;
    return 0;
}