#include<bits/stdc++.h>
using namespace std;

//bellmanford
//在这道题中使用bellman_ford算法会TLE，需要使用dijkstra
const int INF = 0x3f3f3f3f;

struct Edge{
    int u;
    int v;
    int w;
};

vector<Edge>edges;
vector<int>dist;

// bool comp(const Edge& a, const Edge& b) {
//     return a.w < b.w;
// }

void bellman_ford(int s, int n) {

    //bellman_ford这里不用sort, 在最小生成树算法中需要
    // sort(edges.begin(), edges.end(), comp);
    dist[s] = 0;
    bool flag = false;
    for(int i = 0;i < n;i++) {
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








//dijkstra
// const int MAX = 0x3f3f3f3f;
// struct Edge{
//     int v;
//     int w;
// };
// struct Node{
//     int u;
//     int d;
//     bool operator<(const Node& other) const {
//         return d > other.d;
//     }
// };
// vector<vector<Edge>>edges;
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
//     edges.resize(n+1);
//     dist.resize(n+1, MAX);
//     vis.resize(n+1, false);
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges[u].push_back({v, w});
//     }
//     dijkstra(s);
//     for(int i = 1;i <= n;i++) {
//         cout << dist[i] << ' ';
//     }
//     return 0;
// }