// #include<bits/stdc++.h>
// using namespace std;

// //dijkstra
// struct edge{
//     int v;
//     double w;
//     edge(int v1, double w1) : v(v1), w(w1) {}
// };

// struct node{
//     int u;
//     double d;
//     node(int u1, double d1) : u(u1), d(d1) {}
//     bool operator<(const node& other) const {
//         return d > other.d;
//     }
// };

// const double INF = 0x3f3f3f3f;
// vector<vector<edge>>edges;
// vector<double>dist;
// vector<bool>vis;

// double dijkstra(int a, int b) {
//     //反向求解
//     dist[b] = 100.0;
//     priority_queue<node>q;
//     q.push({b, dist[b]});
//     while(!q.empty()) {
//         auto [u, d] = q.top();
//         q.pop();
//         if(vis[u]) continue;
//         vis[u] = true;
//         for(auto [v, w] : edges[u]) {
//             if(dist[v] > dist[u] / w) {
//                 dist[v] = dist[u] / w;
//                 q.push({v, dist[v]});
//             }
//         }
//     }
//     return dist[a];
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m, a, b;
//     cin >> n >> m;
//     edges.resize(n+1), dist.resize(n+1, INF), vis.resize(n+1, false);
//     for(int i = 0;i < m;i++) {
//         int x, y, z;
//         cin >> x >> y >> z;
//         edges[x].push_back({y, double(100-z)/100});
//         edges[y].push_back({x, double(100-z)/100});
//     }
//     cin >> a >> b;
//     cout << fixed << setprecision(8) << dijkstra(a, b);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u;
    int v;
    double w;
    edge(int u1, int v1, double w1) : u(u1), v(v1), w(w1) {}
};

const double INF = 0x3f3f3f3f;
vector<edge>edges;
vector<double>dist;

double bellman_ford(int a, int b, int n) {
    int cnt = 0;
    dist[b] = 100;
    bool flag = false;
    for(int i = 0;i < n-1;i++) {
        flag = false;
        for(auto [u, v, w] : edges) {
            if(dist[u] != INF && dist[v] > dist[u] / w) {
                dist[v] = dist[u] / w;
                flag = true;
            }
        }
        if(!flag) break;
    }
    return dist[a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, a, b;
    cin >> n >> m;
    dist.resize(n+1, INF);
    for(int i = 0;i < m;i++) {
        int x, y, z;
        double w;
        cin >> x >> y >> z;
        w = double(100-z)/100;
        edges.push_back({x, y, w});
        edges.push_back({y, x, w});
    }
    cin >> a >> b;
    cout << fixed << setprecision(8) << bellman_ford(a, b, n);
    return 0;
}