#include<bits/stdc++.h>
using namespace std;



// void dfs(int u) {
//     if(edges[u].size() == 0) {
//         ans++;
//         ans %= MOD;
//     }
//     for(auto v : edges[u]) {
//         dfs(v);
//     }
//     return;
// }
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    int MOD = 80112002;
    vector<vector<int>>edges;
    vector<int> du;
    vector<int>dp;
    vector<int>chu;
    edges.resize(n+1), du.resize(n+1), dp.resize(n+1, 0);
    chu.resize(n+1);
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        du[b]++;
        chu[a]++;
    }
    //用dfsTLE，感觉可以用dp
    // for(int i = 1;i <= n;i++) {
    //     if(!be[i]) {
    //         dfs(i);
    //     }
    // }
    queue<int>node;
    for(int i = 1;i <= n;i++) {
        if(du[i] == 0) {
            node.push(i);
            dp[i] = 1;
        }
    }
    while(!node.empty()) {
        int front = node.front();
        //dp转移方程
        for(auto v : edges[front]) {
            dp[v] += dp[front];
            dp[v] %= MOD;
            du[v]--;
            if(du[v] == 0) node.push(v);
        }
        node.pop();
    }
    for(int i = 1;i <= n;i++) {
        if(chu[i] == 0) {
            ans += dp[i];
            ans %= MOD;
        }
    }
    cout << ans;
    return 0;
}