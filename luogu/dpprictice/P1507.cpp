#include<bits/stdc++.h>
using namespace std;

struct food{
    int v;
    int m;
    int k;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, t, n;
    cin >> h >> t >> n;
    vector<food>foods(n);
    for(int i = 0;i < n;i++) {
        int v, m, k;
        cin >> v >> m >> k;
        foods[i] = {v, m, k};
    }
    vector<vector<int>>dp(h+1, vector<int>(t+1, 0));
    for(auto [v, m, k] : foods) {
        for(int i = h;i >= v;i--) {
            for(int j = t;j >= m;j--) {
                dp[i][j] = max(dp[i][j], dp[i-v][j-m] + k);
            }
        }
    }
    cout << dp[h][t];
    return 0;
}