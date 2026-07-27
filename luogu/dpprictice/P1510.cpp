#include<bits/stdc++.h>
using namespace std;

struct stone{
    int k;
    int m;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, n, c;
    cin >> v >> n >> c;
    vector<stone>stones(n);
    for(int i = 0;i < n;i++) {
        int k, m;
        cin >> k >> m;
        stones[i] = {k, m};
    }
    vector<int>dp(c+1, 0);
    for(auto [k, m] : stones) {
        for(int i = c;i >= m;i--) {
            dp[i] = max(dp[i], dp[i-m] + k);
        }
    }
    int ans = 0;
    for(int i = 1;i <= c;i++) {
        if(dp[i] >= v) {
            ans = i;
            break;
        }
    }
    if(ans == 0) {
        cout << "Impossible";
    } else {
        cout << c-ans;
    }
    return 0;
}