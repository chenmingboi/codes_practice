#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct edge{
    int v;
    int w;
};

struct node{
    int u;
    int d;
    bool operator<(const node& other) const {
        return d > other.d;
    }
};

vector<int>dist;
vector<bool>vis;

void dijkstra(int s,const vector<vector<edge>>&edges) {
    dist[s] = 0;
    priority_queue<node>q;
    q.push({s, dist[s]});
    while(!q.empty()) {
        auto [u, d] = q.top();
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v, w] : edges[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({v, dist[v]});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    dist.resize(n+1, INF);
    vis.resize(n+1, false);
    vector<vector<edge>>edges(n+1);
    vector<vector<edge>>re_edges(n+1);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        //反向图
        re_edges[v].push_back({u, w});
    }
    //在正向图和方向图上各做一次dijkstra即可
    long long ans = 0LL;
    dijkstra(1, edges);
    for(int i = 1;i <= n;i++) ans += dist[i];
    vis.assign(n+1, false);
    dist.assign(n+1, INF);
    dijkstra(1, re_edges);
    for(int i = 1;i <= n;i++) ans += dist[i];
    cout << ans;
    return 0;
}
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     //用floyd MLE，做完了才发现是单源最短路径问题
//     vector<vector<int>>dist(n+1, vector<int>(n+1, INF));
//     for(int i = 1;i <= n;i++) dist[i][i] = 0;
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         dist[u][v] = w;
//     }
//     for(int k = 1;k <= n;k++) {
//         for(int i = 1;i <= n;i++) {
//             for(int j = 1;j <= n;j++) {
//                 if(dist[i][k] != INF && dist[k][j] != INF) {
//                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                 }
//             }
//         }
//     }
//     long long ans = 0LL;
//     for(int i = 1;i <= n;i++) {
//         ans += dist[1][i];
//         ans += dist[i][1];
//     }
//     cout << ans;
//     return 0;

// }