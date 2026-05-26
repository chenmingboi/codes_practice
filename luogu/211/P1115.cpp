#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n+1);
    // vector<int>dp(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    // dp[1] = a[1];
    int ans = -0x3f3f3f3f;
    //这里可以空间优化，因为只用到了dp[i]和dp[i-1]这两个数，且之后循环过后不会读取dp
    int tempans = a[1];
    for(int i = 2;i <= n;i++) {
        //每个数都有两种选择，一种是单独成为一个序列的开始
        //另一种是加入之前一个序列
        // dp[i] = max(a[i], dp[i-1]+a[i]);
        // ans = max(ans, dp[i]);
        tempans = max(a[i], tempans + a[i]);
        ans = max(tempans, ans);
    }
    cout << ans;
    return 0;
}