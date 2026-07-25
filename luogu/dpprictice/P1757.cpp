#include<bits/stdc++.h>
using namespace std;

struct wupin{
    int w;
    int v;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<vector<wupin>>th(105);
    int maxc = 0;
    for(int i = 0;i < n;i++) {
        int w, v, c;
        cin >> w >> v >> c;
        th[c].push_back({w, v});
        maxc = max(maxc, c);
    }
    vector<int>dp(m+1, 0);
    //遍历每一个组
    for(int i = 0;i <= maxc;i++) {
        if(th[i].empty()) continue;
        //逆序遍历容量，保证在最里面更新dp的时候使用的dp[j-w]是上一个组别更新过后的
        for(int j = m;j >= 0;j--) {
            for(auto [w, v] : th[i]) {
                //针对同一容量遍历这个组别中的所有物品保留在该容量下使得value最大的一个物品
                //因为这个更新公式是对改组别中的所有物品进行比较，取其中的max，也就是只取一个
                if(j >= w) {
                    dp[j] = max(dp[j], dp[j-w] + v);
                }
            }
        }
    }
    cout << dp[m];
    return 0;
}