#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<bool>vis;
vector<int>colors;
vector<int>cnt(2);
void dfs(int u) {
    vis[u] = true;
    cnt[colors[u]]++;
    for(auto v : edges[u]) {
        if(!vis[v]) {
            colors[v] = colors[u] ^ 1;
            dfs(v);
        }
    }
    vis[u] = false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    edges.resize(n+1);
    vis.resize(n+1, false);
    colors.resize(n+1, 0);
    for(int i = 0;i < n-1;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    cnt[0] = cnt[1] = 0;
    //只需要染一次就够了，输出每个节点颜色的数量即可
    dfs(1);
    for(int i = 1;i <= n;i++) {
        cout << cnt[colors[i]] << ' ';
    }
    return 0;
}