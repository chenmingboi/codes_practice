#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c, h;
    cin >> c >> h;
    vector<int>v(h+1);
    for(int i = 1;i <= h;i++) cin >> v[i];
    vector<bool>dp(c+1, false);
    dp[0] = true;
    for(int i = 1;i <= h;i++) {
        for(int j = c;j >= v[i];j--) {
            dp[j] = dp[j] || dp[j-v[i]];
        }
    }
    for(int i = c;i >= 0;i--) {
        if(dp[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}