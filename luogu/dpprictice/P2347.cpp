#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int>weight = {1, 2, 3, 5, 10, 20};
    vector<int>num(6);
    //dp[i] = true表示可以称出ig
    vector<bool>dp(1001, false);
    dp[0] = true;
    for(int i = 0;i < 6;i++) cin >> num[i];
    //多重背包
    for(int i = 0;i < 6;i++) {
        for(int j = 1000;j >= 0;j--) {
            for(int k = 0;k <= num[i];k++) {
                if(j >= weight[i] * k) {
                    dp[j] = dp[j] || dp[j-weight[i] * k];
                }
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= 1000;i++) {
        if(dp[i]) ans++;
    }
    cout << "Total=" << ans;
    return 0;
}