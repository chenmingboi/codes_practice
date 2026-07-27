#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<bool>vis;
vector<int>colors;
vector<int>cnt(2, 0);

void dfs(int u) {
    vis[u] = true;
    cnt[colors[u]]++;
    for(auto v : edges[u]) {
        if(vis[v]) {
            continue;
        } else {
            colors[v] = colors[u] ^ 1;
            dfs(v);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1);
    vis.resize(n+1,false);
    colors.resize(n+1, 0);
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    int ans1 = 0, ans2 = 0;
    for(int i = 1;i <= n;i++) {
        //找到一个新的连通分量
        if(!vis[i]) {
            cnt[0] = cnt[1] = 0;
            dfs(i);
            ans1 += min(cnt[0], cnt[1]);
            ans2 += max(cnt[0], cnt[1]);
        }
    }
    cout << ans1 << ' ' << ans2;
    return 0;
}