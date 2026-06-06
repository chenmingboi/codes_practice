#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r;
    cin >> r;
    vector<int>a(r+1), dp(r+1, 0);
    for(int i = 1;i <= r;i++) {
        for(int j = i;j >= 1;j--) {
            cin >> a[j];
            if(j >= 2 && j < i) {
                dp[j] = max(dp[j]+a[j], dp[j-1]+a[j]);
            } else if(j == 1) {
                dp[j] = dp[j] + a[j];
            } else if(j == i) {
                dp[j] = dp[j-1] + a[j];
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= r;i++) ans = max(ans, dp[i]);
    cout << ans;
    return 0;
}
