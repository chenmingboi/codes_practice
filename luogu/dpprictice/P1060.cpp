#include<bits/stdc++.h>
using namespace std;

struct wupin{
    int v;
    int p;
    int m;
};

bool comp(const wupin& a, const wupin& b) {
    if(a.p != b.p) return a.p > b.p;
    return a.v > b.v;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<wupin>th(m);
    for(int i = 0;i < m;i++) {
        int v, p, m;
        cin >> v >> p;
        m = v * p;
        th[i] = {v, p, m};
    }
    sort(th.begin(), th.end(), comp);
    vector<int>dp(n+1, 0);
    // 0/1背包问题
    for(auto [v, p, m] : th) {
        for(int i = n;i >= v;i--) {
            dp[i] = max(dp[i], dp[i-v] + m);
        }
    }
    cout << dp[n];
    return 0;
}