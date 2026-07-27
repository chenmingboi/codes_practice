#include<bits/stdc++.h>
using namespace std;

struct edge{
    int v;
    int w;
};

vector<bool>vis;
vector<vector<edge>>edges;

int ans = 0;
void dfs(int u, int sum) {
    ans = max(ans, sum);
    for(auto [v, w] : edges[u]) {
        if(!vis[v]) {
            vis[v] = true;
            dfs(v, sum + w);
            //回溯
            vis[v] = false;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vis.resize(n+1, false);
    edges.resize(n+1);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    //加入虚拟源节点
    for(int i = 1;i <= n;i++) {
        edges[0].push_back({i, 0});
    }
    //使用深搜
    vis[0] = true;
    dfs(0, 0);
    cout << ans;
    return 0;
}