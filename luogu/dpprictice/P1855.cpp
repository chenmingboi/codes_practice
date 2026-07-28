#include<bits/stdc++.h>
using namespace std;

struct wish{
    int money;
    int time;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, t;
    cin >> n >> m >> t;
    //二维资源背包
    vector<wish>wishs(n);
    vector<vector<int>>dp(m+1, vector<int>(t+1));
    for(int i = 0;i < n;i++) {
        int mi, ti;
        cin >> mi >> ti;
        wishs[i] = {mi, ti};
    }
    for(auto [mi, ti] : wishs) {
        for(int i = m;i >= mi;i--) {
            for(int j = t;j >= ti;j--) {
                dp[i][j] = max(dp[i][j], dp[i-mi][j-ti] + 1);
            }
        }
    }
    cout << dp[m][t];
    return 0;
}