#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        string w;
        cin >> w;
        int n = w.length();
        //dp[i][j]表示把[i,j]区域的子串修改为回文串的最短编辑距离
        vector<vector<int>>dp(n+1, vector<int>(n+1, INF));
        for(int i = 0;i < n;i++) dp[i][i] = 0;
        for(int len = 2;len <= n;len++) {
            for(int i = 0;i+len-1 < n;i++) {
                int j = i+len-1;
                if(w[i] == w[j]) {
                    dp[i][j] = min(dp[i][j], (i+1 > j-1) ? 0 : dp[i+1][j-1]);
                } else {
                    //增加，删除，替换
                    dp[i][j] = min({dp[i][j], dp[i+1][j]+1, dp[i][j-1]+1, (i+1 > j-1) ? 1 : dp[i+1][j-1]+1});
                }
            }
        }
        cout << dp[0][n-1] << '\n';
    }
    return 0;
}