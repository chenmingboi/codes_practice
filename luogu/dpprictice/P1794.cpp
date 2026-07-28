#include<bits/stdc++.h>
using namespace std;

struct weapon{
    int t;
    int v;
    int g;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //二维费用背包
    int v, g, n;
    cin >> v >> g >> n;
    vector<weapon>weapons(n);
    vector<vector<int>>dp(v+1, vector<int>(g+1));

    for(int i = 0;i < n;i++) {
        int t, v, g;
        cin >> t >> v >> g;
        weapons[i] = {t, v, g};
    }
    for(auto [t, v1, g1] : weapons) {
        for(int j = v;j >= 1;j--) {
            for(int k = g;k >= 1;k--) {
                if(j >= v1 && k >= g1) {
                    dp[j][k] = max(dp[j][k], dp[j-v1][k-g1] + t);
                }
            }
        }
    }
    cout << dp[v][g];
    return 0;
}