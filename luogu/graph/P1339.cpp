#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct Edge{
    int u;
    int v;
    int w;
};
vector<Edge>edges;
vector<int>dist;

void bellman_ford(int s, int n) {
    dist[s] = 0;
    bool flag = false;
    for(int i = 0;i < n-1;i++) {
        flag = false;
        for(auto [u, v, w] : edges) {
            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                flag = true;
            }
        }
        if(!flag) break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    dist.resize(n+1, INF);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        //无向图
        edges.push_back({u, v, w});
        edges.push_back({v, u, w});
    }
    bellman_ford(s, n);
    cout << dist[t];
    return 0;
}

//dijkstra
// struct edge{
//     int v;
//     int w;
// };

// struct Node{
//     int u;
//     //这里的d指的是s到u的距离
//     int d;
//     bool operator<(const Node& other) const {
//         return d > other.d;
//     }
// };

// vector<vector<edge>>edges;
// vector<int>dist;
// vector<bool>vis;

// void dijkstra(int s) {
//     dist[s] = 0;
//     priority_queue<Node>q;
//     q.push({s, dist[s]});
//     while(!q.empty()) {
//         auto [u, d] = q.top();
//         q.pop();
//         if(vis[u]) continue;
//         vis[u] = true;
//         for(auto [v, w] : edges[u]) {
//             if(dist[v] > dist[u] + w) {
//                 dist[v] = dist[u] + w;
//                 q.push({v, dist[v]});
//             }
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m, s, t;
//     cin >> n >> m >> s >> t;
//     edges.resize(n+1);
//     dist.resize(n+1, INF);
//     vis.resize(n+1, false);
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges[u].push_back({v, w});
//         edges[v].push_back({u, w});
//     }
//     dijkstra(s);
//     cout << dist[t];
//     return 0;
// }