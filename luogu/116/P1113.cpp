#include<bits/stdc++.h>
using namespace std;

vector<int>need;
vector<int>dp;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    need.resize(n+1), dp.resize(n+1);
    for(int i = 0;i < n;i++) {
        int xuhao, len;
        cin >> xuhao >> len;
        need[xuhao] = len;
        int zhunbei, max_pre_time = 0;
        //dp转移公式
        while(cin >> zhunbei && zhunbei != 0) {
            max_pre_time = max(dp[zhunbei], max_pre_time);
        }
        dp[xuhao] = max_pre_time + len;
        ans = max(ans, dp[xuhao]);
    }
    cout << ans;
    return 0;
}