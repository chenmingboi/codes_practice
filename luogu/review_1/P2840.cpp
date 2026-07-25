#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    vector<int>dp(w+1, 0);
    //支付0元只有一种方案，就是不用付钱
    dp[0] = 1;
    for(int i = 1;i <= w;i++) {
        //分别列举n种纸币作为最后一张
        for(int j = 1;j <= n;j++) {
            if(i >= a[j]) {
                dp[i] += dp[i-a[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[w];
    return 0;
}