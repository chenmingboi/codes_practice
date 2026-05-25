#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    //dp[i]表示凑出w的金额最少可以用多少张纸币凑出来
    vector<int>dp(10005, INF), a(n);
    dp[0] = 0;
    for(int i = 0;i < n;i++) {
        int num;
        cin >> num;
        a[i] = num;
        dp[num] = 1;
    }
    for(int i = 1;i <= w;i++) {
        for(int j = 0;j < n;j++) {
            if(i-a[j] >= 0) {
                dp[i] = min(dp[i], dp[i-a[j]] + 1);
            }
        }
    }
    cout << dp[w];
    return 0;
}