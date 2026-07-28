#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int>a(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    sort(a.begin(), a.end());
    vector<int>dp(w+1, 0);
    dp[0] = 1;
    // //这里顺序搞反了，dp[j]是依赖于dp[j-1]的完整方案的，所以更新完dp[j-1]之后才能跟新dp[j]
    // for(int i = 1;i <= n;i++) {
    //     //以a[i]结尾
    //     for(int j = a[i];j <= w;j++) {
    //         dp[j] += dp[j-a[i]];
    //         dp[j] %= MOD;
    //     }
    // }
    for(int i = 1;i <= w;i++) {
        //枚举a[j]作为最后一个元素
        //这里如果要把a[j] <= i写在循环条件中就默认a是从小到大排好的
        //但是题目中并没有说明，所以可以自己先排一下
        //或者就不要把a[j] <= i写在循环条件中而是在循环中加一个if判断
        for(int j = 1;a[j] <= i && j <= n;j++) {
            dp[i] += dp[i-a[j]];
            dp[i] %= MOD;
        }
    }
    cout << dp[w];
    return 0;
}