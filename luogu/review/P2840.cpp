#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int>a(n+1), dp(w+1, 0);
    for(int i = 1;i <= n;i++) cin >> a[i];
    dp[0] = 1;//支付0元就一种方式就是不用支付
    // //枚举最后一张支付纸币的金额
    // for(int i = 1;i <= n;i++) {
    //     for(int j = a[i];j <= w;j++) {
    //         dp[w] += dp[w-a[i]];
    //     }
    // }
    for(int i = 1;i <= w;i++) {
        //枚举最后一张纸币的金额，注意这里是在内层循环
        //因为要对某个w确定下来其支付种类数
        for(int j = 1;j <= n;j++) {
            if(a[j] <= i) {
                dp[i] += dp[i-a[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[w];
    return 0;
}









// #include<bits/stdc++.h>
// using namespace std;

// const int MOD = 1e9+7;
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, w;
//     cin >> n >> w;
//     vector<int>a(n+1);
//     for(int i = 1;i <= n;i++) {
//         cin >> a[i];
//     }
//     vector<int>dp(w+1);
//     dp[0] = 1;
//     for(int i = 1;i <= w;i++) {
//         for(int j = 1;j <= n;j++) {
//             //列举最后一张是哪个金额的纸币
//             if(a[j] <= i) {
//                 dp[i] += dp[i-a[j]];
//                 dp[i] %= MOD;
//             }
//         }
//     }
//     cout << dp[w];
//     return 0;
// }