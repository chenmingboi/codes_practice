#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int v, n;
    cin >> v >> n;
    vector<int>tiji(n+1), dp(v+1);
    for(int i = 1;i <= n;i++) {
        cin >> tiji[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = v;j >= tiji[i];j--){
            dp[j] = max(dp[j], dp[j-tiji[i]] + tiji[i]);
        }
    }
    cout << v - dp[v];
    return 0;
}