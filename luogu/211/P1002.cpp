#include<bits/stdc++.h>
using namespace std;

vector<int>dx = {-2, -2, -1, -1, 0, 1, 1, 2, 2};
vector<int>dy = {-1, 1, -2, 2, 0, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int xb, yb, xm, ym;
    cin >> xb >> yb >> xm >> ym;
    vector<vector<int>>dp(21, vector<int>(21, 0));
    dp[0][0] = 1;
    for(int i = 0;i < 9;i++) {
        int newx = xm+dx[i], newy = ym+dy[i];
        if(newx >= 0 && newy <= 20 && newy >= 0 && newy <= 20) {
            dp[newx][newy] = 0;
        }
        dp[xm+dx[i]][ym+dy[i]] = 0;
    }
    for(int i = 0;i <= xb;i++) {
        for(int j = 0;j <= yb;j++) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    cout << dp[xb][yb];
    return 0;
}