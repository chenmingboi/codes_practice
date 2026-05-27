#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>num(n+1);
    //注意这里edges是反向记录的
    vector<vector<int>>edges(n+1);
    //dp[i]表示走到地窖i最多挖到的地雷
    vector<int>dp(n+1);
    //pre[i]表示节点i的pre节点
    vector<int>pre(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> num[i];
        pre[i] = i;
        dp[i] = num[i];
    }
    for(int i = 1;i <= n-1;i++) {
        for(int j = i+1;j <= n;j++) {
            int lu;
            cin >> lu;
            if(lu) edges[j].push_back(i);
        }
    }
    dp[0] = 0;
    for(int i = 1;i <= n;i++) {
        int tempre = i;
        int ma = 0;
        for(auto j : edges[i]) {
            if(j < i && dp[j] > ma) {
                tempre = j;
                ma = dp[j];
            }
        }
        if(ma) {
            dp[i] += dp[tempre];
            pre[i] = tempre;
        }
    }
    int node = 1, ans = 1;
    for(int i = 2;i <= n;i++) {
        if(dp[i] > dp[node]) node = i;
    }
    ans = node;
    vector<int>path;
    while(pre[node] != node) {
        path.push_back(node);
        node = pre[node];
    }
    path.push_back(node);
    reverse(path.begin(), path.end());
    for(auto it : path) {
        cout << it << ' ';
    }
    cout << endl << dp[ans];
    return 0;
}