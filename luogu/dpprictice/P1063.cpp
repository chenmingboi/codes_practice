#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>>zhuzi(2*n);
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        zhuzi[i].first = num;
        if(i == 0){
            zhuzi[n-1].second = num;
        } else {
            zhuzi[i-1].second = num;
        }
    }
    for(int i = n;i < 2*n;i++) zhuzi[i] = zhuzi[i-n];
    vector<vector<int>>dp(2*n, vector<int>(2*n));
    for(int i = 0;i < 2*n;i++) dp[i][i] = 0;
    for(int len = 2;len <= n;len++) {
        for(int i = 0;i+len-1 < 2*n;i++) {
            int j = i+len-1;
            for(int k = i;k < j;k++) {
                int value = zhuzi[i].first * zhuzi[k].second * zhuzi[j].second;
                dp[i][j] = max(dp[i][j], dp[i][k] + dp[k+1][j] + value);
            }
        }
    }
    int ans = 0;
    for(int i = 0;i < n;i++) ans = max(ans, dp[i][i+n-1]);
    cout << ans;
    return 0;
}