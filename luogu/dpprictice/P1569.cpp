#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>a(n+1), pref(n+1, 0);
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++) {
        pref[i] = pref[i-1] + a[i];
    }
    //dp[i]表示前i各元素可以最多分成多少合理的组别
    vector<int>dp(n+1, INT_MIN);
    dp[0] = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = 0;j < i;j++) {
            //考虑最后一组从j+1->i如果dp[j] > 0并且pref[i] - pref[j] >= 0此时dp[i] = max(dp[i], dp[j] + 1);
            if(dp[j] != INT_MIN && pref[i] - pref[j] >= 0) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    if(dp[n] < 0) {
        cout << "Impossible";
    } else {
        cout << dp[n];
    }
    return 0;
}