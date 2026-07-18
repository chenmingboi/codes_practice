#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>weight;
vector<int>dp;
int totalweight;

void setSubTree(int u, int pre, int depth) {
    dp[1] += weight[u] * depth;
    for(auto v : edges[u]) {
        if(v == pre) continue;
        setSubTree(v, u, depth+1);
        weight[u] += weight[v];
    }
}

void dfs(int u, int pre) {
    for(auto v : edges[u]) {
        if(v != pre) {
            dp[v] = dp[u] - weight[v] + totalweight - weight[v];
            dfs(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    weight.resize(n+1), edges.resize(n+1), dp.resize(n+1);
    for(int i = 1;i <= n;i++) {
        int w, u, v;
        cin >> w >> u >> v;
        weight[i] = w;
        totalweight += w;
        if(u != 0) {
            edges[i].push_back(u);
            edges[u].push_back(i);
        }
        if(v != 0) {
            edges[i].push_back(v);
            edges[v].push_back(i);
        }
    }
    int ans = INT_MAX;
    setSubTree(1, 0, 0);
    dfs(1, 0);
    for(int i = 1;i <= n;i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans;
    return 0;
}