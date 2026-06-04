#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

//dijkstra
// struct Edge {
//     int v;
//     int w;
// };

// struct Node{
//     int u;
//     int d;
//     bool operator>(const Node& other) const {
//         return d > other.d;
//     }
// };

// vector<vector<Edge>>edges;
// vector<int>dist;
// vector<bool>vis;

// void dijkstra(int s, int n) {
//     priority_queue<Node, vector<Node>, greater<Node>>q;
//     q.push({s, 0});
//     dist[s] = 0;
//     while(!q.empty()) {
//         int u = q.top().u, d = q.top().d;
//         q.pop();
//         if(vis[u]) continue;
//         vis[u] = true;
//         for(auto edge : edges[u]) {
//             int v = edge.v, w = edge.w;
//             if(dist[v] > d + w) {
//                 dist[v] = d + w;
//                 q.push({v, dist[v]});
//             }
//         }
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m, s;
//     cin >> n >> m >> s;
//     edges.resize(n+1), dist.resize(n+1, INF);
//     vis.resize(n+1, false);
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges[u].push_back({v, w});
//     }
//     dijkstra(s, n);
//     for(int i = 1;i <= n;i++) cout << dist[i] << ' ';
//     return 0;
// }

//此题bellman_ford会TLE因为bellman_ford的复杂度为O(nm)
//而dijkstra没问题，复杂度为O(nlogm)
struct Edge{
    int u;
    int v;
    int w;
};

bool comp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

vector<Edge>edges;
vector<int>dist;

bool bellman_ford(int s, int n) {
    // sort(edges.begin(), edges.end(), comp);
    dist[s] = 0;
    bool gengxin = false;
    //这里是非负权，所以可以用while true
    //如果是带有负权的，不可以用while true
    //改为循环n次， 且可以判定有没有负环
    // while(true) {
    // for(int i = 1;i <= n;i++) {
    while(true) {
        gengxin = false;
        for(auto edge : edges) {
            int u = edge.u, v = edge.v, w = edge.w;
            if(dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                gengxin = true;
            }
        }
        if(!gengxin) break;
    }
    //如果最后一个循环还在更新dist，说明有负环
    if(gengxin) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    edges.resize(m);
    dist.resize(n+1, INF);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[i] = {u, v, w};
    }
    bellman_ford(s, n);
    for(int i = 1;i <= n;i++) cout << dist[i] << ' ';
    return 0;
}