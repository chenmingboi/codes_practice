#include<bits/stdc++.h>
using namespace std;

struct edge{
    int v;
    int w;
    bool operator<(const edge& other) const {
        return w > other.w;
    }
};
vector<vector<edge>>edges;
vector<bool>vis;

int bfs(int s, int t) {
    int ans = 0;
    priority_queue<edge>q;
    q.push({s, 0});
    while(!q.empty() && !vis[t]) {
        auto [u, w] = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        ans = max(ans, w);
        for(auto [v, w1] : edges[u]) {
            if(!vis[v]) {
                q.push({v, w1});
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    edges.resize(n+1);
    vis.resize(n+1, false);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    cout << bfs(s, t);
    return 0;
}