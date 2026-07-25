#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>>zujin(n, vector<int>(n+1, 0));
    for(int i = 1;i < n;i++) {
        for(int j = i+1;j <= n;j++) {
            int price;
            cin >> price;
            zujin[i][j] = price;
        }
    }
    vector<int>dp(n+1, INF);
    dp[0] = 0, dp[1] = 0;
    for(int i = 2;i <= n;i++) {
        for(int j = 1;j < i;j++) {
            dp[i] = min(dp[i], dp[j] + zujin[j][i]);
        }
    }
    cout << dp[n];
    return 0;
}