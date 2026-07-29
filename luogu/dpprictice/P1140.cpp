#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //感觉和最小编辑距离很像
    //推荐看第一篇题解中的思路，很清晰
    int n1, n2;
    string s1, s2;
    cin >> n1 >> s1 >> n2 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    unordered_map<int, int>mp;
    mp['A' + 'A'] = 5, mp['A'+'C'] = -1, mp['A' + 'G'] = -2, mp['A' + 'T'] = -1, mp['A' + '-'] = -3;
    mp['C' + 'C'] = 5, mp['C'+'G'] = -3, mp['C'+'T'] = -2, mp['C'+'-'] = -4;
    mp['G' + 'G'] = 5, mp['G'+'T'] = -2, mp['G'+'-'] = -2;
    mp['T'+'T'] = 5, mp['T'+'-'] = -1;
    //dp[i][j]表示第一个基因前i个碱基对和第二个基因前j个碱基对之间的最大相似度
    vector<vector<int>>dp(n1+1, vector<int>(n2+1));
    //针对最后一个碱基对来写递推公式
    //有三种情况s1[i]对s2[j], 2. s1[i]对空碱基 3.空碱基对s2[j]，没有办法空碱基对空碱基
    dp[0][0] = 0;
    //处理边界
    for(int i = 1;i <= n1;i++) dp[i][0] = dp[i-1][0] + mp[s1[i]+'-'];
    for(int i = 1;i <= n2;i++) dp[0][i] = dp[0][i-1] + mp['-'+s2[i]];
    //递推
    for(int i = 1;i <= n1;i++) {
        for(int j = 1;j <= n2;j++) {
            dp[i][j] = max({dp[i-1][j-1] + mp[s1[i] + s2[j]], dp[i-1][j] + mp[s1[i] + '-'], dp[i][j-1] + mp['-' + s2[j]]});
        }
    }
    cout << dp[n1][n2];
    return 0;

}