#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
struct Edge{
    int v;
    long long w;
};

struct Node {
    int u;
    long long d;
    bool operator>(const Node& other) const {
        return d > other.d;
    }
};

vector<vector<Edge>>edges;


void dijkstra(int s, int n, vector<bool>& vis, vector<long long>& dist) {
    priority_queue<Node, vector<Node>, greater<Node>>q;
    q.push({s, 0});
    while(!q.empty()) {
        int u = q.top().u;
        long long d = q.top().d;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto edge : edges[u]) {
            int v = edge.v;
            long long w = edge.w;
            if(dist[v] > d + w) {
                dist[v] = d + w;
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
    edges.resize(n+1);
    for(int i = 0;i < m;i++) {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
    }
    vector<bool>vis;
    vector<long long>dist;
    vis.assign(n+1, false), dist.assign(n+1, INF);
    dijkstra(1, n, vis, dist);
    long long ans = 0;
    for(int i = 2;i <= n;i++) {
        ans += dist[i];
    }
    for(int i = 2;i <= n;i++) {
        vis.assign(n+1, false), dist.assign(n+1, INF);
        dijkstra(i, n, vis, dist);
        ans += dist[1];
    }
    cout << ans;
    return 0;
}

//floyd
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     vector<vector<long long>>dist(n+1, vector<long long>(n+1, INF));
//     for(int i = 0;i < m;i++ ) {
//         long long u, v, w;
//         cin >> u >> v >> w;
//         dist[u][v] = min(dist[u][v], w);
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
//     long long ans = 0;
//     for(int i = 2;i <= n;i++) {
//         ans += dist[1][i];
//         ans += dist[i][1];
//     }
//     cout << ans;
//     return 0;
// }