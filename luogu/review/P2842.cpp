#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

//一维
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    //dp[i]表示凑出金额i需要的最少纸币张数
    vector<int>a(n+1), dp(w+1, INF);
    for(int i = 1;i <= n;i++) cin >> a[i];
    dp[0] = 0;
    for(int i = 1;i <= n;i++) {
        for(int j = a[i];j <= w;j++) {
            //dp[j-a[i]]对应的是dp[i][j-a[i]], 此时的dp[j-a[i]]是对于当前i已经更新过了，不是上一轮i-1的dp[i-1][j-a[i]]
            // min函数里面的dp[j]对应的是dp[i-1][j], 这个状态来源于上一轮对于i-1的循环
            dp[j] = min(dp[j-a[i]]+1, dp[j]);
        }
    }
    cout << dp[w];
    return 0;
}
// //二维
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     //完全背包问题
//     int n, w;
//     cin >> n >> w;
//     vector<int>a(n+1);
//     //dp[i][j]表示用前i种纸币凑出j的金额最少用多少张纸币可以凑出来
//     //初始化为INF，因为有些金额是凑不出来的，不能用0来初始化
//     vector<vector<int>>dp(n+1, vector<int>(w+1, INF));
//     for(int i = 1;i <= n;i++) cin >> a[i];
//     //表示前i种纸币凑出金额为0 需要的纸币张数为0
//     for(int i = 0;i <= n;i++) dp[i][0] = 0;
//     for(int i = 1;i <= n;i++) {
//         for(int j = 1;j <= w;j++) {
//             //选当前种类纸币和不选当前种类纸币
//             if(j >= a[i]) {
//                 dp[i][j] = min(dp[i][j-a[i]]+1, dp[i-1][j]);
//             } else {
//                 dp[i][j] = dp[i-1][j];
//             }
//         }
//     }
//     cout << dp[n][w];
//     return 0;
// }