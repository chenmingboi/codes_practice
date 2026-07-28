#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //0/1背包
    int h, n;
    cin >> h >> n;
    vector<int>weight(n+1);
    for(int i = 1;i <= n;i++) cin >> weight[i];
    //dp[i] = true表示可以准确地吃到这么多，类似于砝码称重那道题
    vector<bool>dp(h+1, false);
    dp[0] =  true;
    for(int i = 1;i <= n;i++) {
        for(int j = h;j >= weight[i];j--) {
            dp[j] = dp[j] || dp[j-weight[i]];
        }
    }
    for(int i = h;i >= 0;i--) {
        if(dp[i]) {
            cout << i;
            break;
        }
    }
    return 0;
}