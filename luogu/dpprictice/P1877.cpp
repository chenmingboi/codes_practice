#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, beginLevel, maxLevel;
    cin >> n >> beginLevel >> maxLevel;
    vector<int>c(n+1);
    for(int i = 1;i <= n;i++) cin >> c[i];
    //这里dp[i][j]表示的是在经过i次调式之后能否达到音量j，即第i首歌曲能否以音量j演奏
    vector<vector<bool>>dp(n+1, vector<bool>(maxLevel+1));
    dp[0][beginLevel] = true;
    for(int i = 1;i <= n;i++) {
        for(int j = maxLevel;j >= 0;j--) {
            if(!dp[i-1][j]) continue;
            if(j+c[i] <= maxLevel) dp[i][j+c[i]] = true;
            if(j-c[i] >= 0) dp[i][j-c[i]] = true;
        }
    }
    bool flag = false;
    for(int i = maxLevel;i >= 0;i--) {
        if(dp[n][i]) {
            cout << i;
            flag = true;
            break;
        }
    }
    if(!flag) cout << -1;
    return 0;
}