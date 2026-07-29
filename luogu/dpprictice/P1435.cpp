// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string s;
//     cin >> s;
//     string rev_s = s;
//     reverse(rev_s.begin(), rev_s.end());
//     int n = s.size();
//     //详细思路解释看题解1
//     //dp[i][j] 表示 s 前 i 个字符 和 rs 前 j 个字符的 LCS 长度
//     vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
//     for(int i = 1;i <= n;i++) {
//         for(int j = 1;j <= n;j++){
//             if(s[i-1] == rev_s[j-1]) {
//                 dp[i][j] = dp[i-1][j-1]+1;
//             } else {
//                 dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
//             }
//         }
//     }
//     cout << n - dp[n][n];
//     return 0;
// }

//区间dp做法
#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    //表示将i到j区域内改成回文词最少需要插入的字符数
    vector<vector<int>>dp(n, vector<int>(n, INF));
    dp[0][0] = 0;
    for(int i = 0;i < n;i++) dp[i][i] = 0;
    for(int len = 2;len <= n;len++) {
        for(int i = 0;i+len-1 < n;i++) {
            int j = i+len-1;
            if(s[i] == s[j]) {
                //当len=2的时候j = i+1,此时i+1 > j-1dp[i][j]应该赋值为0，而不是INF
                dp[i][j] = ((i+1 > j-1) ? 0 : dp[i+1][j-1]);
            } else {
                //在左边插入或者在右边插入
                dp[i][j] = min(dp[i][j-1], dp[i+1][j])+1;
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}