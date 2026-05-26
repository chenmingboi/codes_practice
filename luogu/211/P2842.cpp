#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int>a(n+1, 0);
    //dp[i][j]表示使用前i种纸币凑出金额为j最少用多少张纸币
    vector<vector<int>>dp(n+1, vector<int>(w+1, INF));
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        dp[i][0] = 0;
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= w;j++) {
            if(j >= a[i]) {
                //不选和选硬币i这两种方案的较小值
                dp[i][j] = min(dp[i-1][j], dp[i][j-a[i]]+1);
            } else {
                //如果总金额小于a[i]则不选a[i]
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    cout << dp[n][w];
    return 0;
}

// //一维优化
// const int INF = 0x3f3f3f3f;
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, w;
//     cin >> n >> w;
//     //dp[i]表示凑出w的金额最少可以用多少张纸币凑出来
//     vector<int>dp(10005, INF), a(n);
//     dp[0] = 0;
//     for(int i = 0;i < n;i++) {
//         int num;
//         cin >> num;
//         a[i] = num;
//         dp[num] = 1;
//     }
//     for(int i = 1;i <= w;i++) {
//         for(int j = 0;j < n;j++) {
//             if(i-a[j] >= 0) {
//                 dp[i] = min(dp[i], dp[i-a[j]] + 1);
//             }
//         }
//     }
//     cout << dp[w];
//     return 0;
// }