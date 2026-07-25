#include<bits/stdc++.h>
using namespace std;

struct person{
    int l;
    int w;
    int u;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<person>people(n);
    for(int i = 0;i < n;i++) {
        int l, w, u;
        cin >> l >> w >> u;
        people[i] = {l, w, u};
    }
    vector<long long>dp(x+1, 0);
    for(auto [l, w, u] : people) {
        for(int i = x;i >= 0;i--) {
            if(i >= u) {
                //当剩余迷药数量多余u时可以选择用或者不用
                dp[i] = max(dp[i] + l, dp[i-u] + w);
            } else {
                //当密钥数量少于u时只能输掉
                dp[i] = max(dp[i], dp[i] + l);
            }
        }
    }
    cout << 5LL * dp[x];
    return 0;
}