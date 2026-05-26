#include<bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //此题不要求不同位置是一种不同的方案
    int n, w;
    cin >> n >> w;
    vector<int>a(n);
    vector<long long>dp(w+1);
    dp[0] = 1;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++) {
        for(int j = 1;j <= w;j++) {
            if(j >= a[i]) {
                //不选a[i]和选a[i]
                dp[j] = dp[j] + dp[j-a[i]];
                dp[j] %= MOD;
            }
        }
    }
    cout << dp[w];
    return 0;

}