#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r;
    cin >> r;
    vector<vector<int>>input(r, vector<int>(r));
    for(int i = 0;i < r;i++) {
        for(int j = 0;j <= i;j++) {
            cin >> input[i][j];
        }
    }
    vector<int>dp(r, 0);
    for(int i = 0;i < r;i++) {
        for(int j = i;j >= 0;j--) {
            if(i == 0 && j == 0) dp[j] = input[i][j];
            if(j == i && j != 0) {
                dp[j] = max(dp[j-1] + input[i][j], dp[j]);
            } else if(j > 0 && j < i) {
                dp[j] = max(dp[j-1] + input[i][j], dp[j] + input[i][j]);
            } else if(j == 0 && j != i) {
                dp[j] = max(dp[j] + input[i][j], dp[j]);
            }
        }
    }
    int ans = INT_MIN;
    for(int i = 0;i < r;i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}