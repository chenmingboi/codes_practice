#include<bits/stdc++.h>
using namespace std;


//完全背包做法，将每个四次方数看作一种物品，每种物品可以无限使用
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m;
    cin >> m;
    vector<int>sici;
    for(int i = 1;i * i * i * i <= m;i++) sici.push_back(i*i*i*i);
    vector<int>dp(m+1, INT_MAX);
    dp[0] = 0;
    for(auto v : sici) {
        for(int i = v;i <= m;i++) {
            dp[i] = min(dp[i], dp[i-v] + 1);
        }
    }
    cout << dp[m];
    return 0;
}

//TLE
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int m;
//     cin >> m;
//     vector<int>dp(m+1, INT_MAX);
//     dp[0] = 1, dp[1] = 1;
//     for(int i = 1;pow(i, 4) <= m;i++) dp[pow(i, 4)] = 1;
//     for(int i = 1;i <= m;i++) {
//         if(dp[i] == 1) continue;
//         for(int j = 1;j <= i-j;j++) {
//             dp[i] = min(dp[i], dp[j] + dp[i-j]);
//         }
//     }
//     cout << dp[m];
//     return 0;
// }