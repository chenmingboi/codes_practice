#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a, b;
    cin >> a >> b;
    a = " " + a;
    b = " " + b;
    int n1 = a.length(), n2 = b.length();
    //dp[i][j]表示A中的前i个字符变成B中的前j个字符最少的字符操作次数
    vector<vector<int>>dp(n1+1, vector<int>(n2+1, INF));
    //预处理
    dp[0][0] = 0;
    for(int i = 1;i <= n1;i++) dp[i][0] = i;
    for(int i = 1;i <= n2;i++) dp[0][i] = i;
    //当题目中出现两个字符串或者其他元素进行比较且允许修改的时候自然要想到针对最后一对元素进行讨论
    //递推，针对最后一对元素
    //三种情况a[i]对b[j], a[i]对空，空对b[j];递推顺序是从小到大
    for(int i = 1;i <= n1;i++) {
        for(int j = 1;j <= n2;j++) {
            dp[i][j] = min({dp[i-1][j-1] + (a[i] == b[j] ? 0 : 1), dp[i-1][j] + 1, dp[i][j-1] + 1});
        }
    }
    cout << dp[n1][n2];
    return 0;
}