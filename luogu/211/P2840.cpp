#include<bits/stdc++.h>
using namespace std;


//一维
const long long MOD = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int>a(n);
    vector<long long>dp(w+1);
    //dp[i]表示凑出金额i的方案数
    //这里设置dp[0]=1是为了下面如果a[j]=i即最后一张也就只有这一张，此时方案数应该加1而不是加0
    dp[0] = 1; //不给钱
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    //如果最后一张纸币面额是 a[j]，那么前面需要凑出：i - a[j]所以：dp[i] += dp[i - a[j]]
    //比如说凑w=3,现在有金额为1和2的那么当a[j] = 1时即 2 + 1 和1 + 1 + 1a[j] = 2时即 1+2
    //这样就区分开了2+1和1+2
    for(int i = 1;i <= w;i++) {
        for(int j = 0;j < n;j++) {
            if(i >= a[j]) {
                dp[i] += dp[i-a[j]];
                dp[i] %= MOD;
            }
        }
    }
    cout << dp[w];
    return 0;
}