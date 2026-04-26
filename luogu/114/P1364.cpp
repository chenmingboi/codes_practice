#include<bits/stdc++.h>
using namespace std;

vector<int>w;
vector<vector<int>>g;

int dfs(int u, int parent, int dist) {
    int sum = w[u] * dist;
    for(auto v : g[u]) {
        if(v == parent) continue;
        sum += dfs(v, u, dist+1);
    }
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //使用无向图，然后暴力枚举医院位置
    int n;
    cin >> n;
    g.resize(n+1), w.resize(n+1);
    for(int i = 1;i <= n;i++) {
        int u, v;
        cin >> w[i] >> u >> v;
        //双向图，添加两条边
        if(u != 0) {
            g[i].push_back(u);
            g[u].push_back(i);
        }
        if(v != 0) {
            g[i].push_back(v);
            g[v].push_back(i);
        }
    }
    int ans = INT_MAX;
    for(int i = 1;i <= n;i++) {
        ans = min(ans, dfs(i, 0, 0));
    }
    cout << ans;
    return 0;
}