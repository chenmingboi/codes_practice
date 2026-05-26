#include<bits/stdc++.h>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //0/1背包问题，但是每个人并不是选或者不选这么简单，
    //这道题的不选相当于加lost[i]而不是什么都不加
    //选的话是花费迷药获得胜利的经验win[i]
    int n, x;
    cin >> n >> x;
    vector<int>lose(n+1), win(n+1), use(n+1);
    //dp[i]表示耗费i个迷药最多获得的经验
    vector<long long>dp(x+1, 0);
    for(int i = 1;i <= n;i++) {
        cin >> lose[i] >> win[i] >> use[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = x;j >= 0;j--) {
            if(j >= use[i]) {
                //可使用的药大于use[i]
                dp[j] = max(dp[j]+lose[i], dp[j-use[i]]+win[i]);
            } else {
                dp[j] = dp[j] + lose[i];
            }
        }
    }
    cout << 5LL * dp[x];
    return 0;
}