#include<bits/stdc++.h>
using namespace std;

struct person{
    int a;
    int b;
    int c;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //二维资源限制0/1背包
    int n, m, x;
    cin >> n >> m >> x;
    vector<person>people(n);
    for(int i = 0;i < n;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        people[i] = {a, b, c};
    }
    vector<vector<int>>dp(m+1, vector<int>(x+1));
    dp[0][0] = 0;
    for(auto [a, b, c] : people) {
        for(int i = m;i >= b;i--) {
            for(int j = x;j >= c;j--) {
                dp[i][j] = max(dp[i][j], dp[i-b][j-c] + a);
            }
        }
    }
    cout << dp[m][x];
    return 0;
}