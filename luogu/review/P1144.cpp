#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 100003;

struct Edge {
    int v;
    int w;
};
vector<vector<int>>edges;
vector<int>ans;
vector<bool>vis;
vector<int>dist;

//这道题更适合用bfs, 这里是无向图，还要添加dist来判断是是否要更新
void bfs() {
    queue<pair<int, int>>q;
    q.push({1, 0});
    while(!q.empty()) {
        int u = q.front().first, fa = q.front().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = true;
        for(auto v : edges[u]) {
            if(v == fa) continue;
            if(dist[v] > dist[u] + 1) {
                dist[v] = dist[u] + 1;
                ans[v] = ans[u];
                q.push({v, u});
            } else if(dist[v] == dist[u] + 1) {
                ans[v] = (ans[v] + ans[u]) % MOD;
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
    ans.resize(n+1, 0);
    vis.resize(n+1, false);
    dist.resize(n+1, INF);
    for(int i = 0;i < m;i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    ans[1] = 1;
    dist[1] = 0;
    bfs();
    for(int i = 1;i <= n;i++) cout << ans[i] << '\n';
    return 0;
}

// //dijkstra
// struct Edge {
//     int v;
//     int w;
// };

// struct Node{
//     int u;
//     int d;
//     int a;
//     bool operator>(const Node& other) const {
//         return d > other.d;
//     }
// };

// vector<vector<Edge>>edges;
// vector<int>vis;
// vector<int>dist;
// vector<int>ans;

// void dijkstra(int n) {
//     priority_queue<Node, vector<Node>, greater<Node>>q;
//     dist[1] = 0;
//     // for(int i = 1;i <= n;i++) {
//     //     if(dist[i] != INF) q.push({i, dist[i]});
//     // }
//     q.push({1, 0, 1});
//     while(!q.empty()) {
//         int u = q.top().u, d = q.top().d, a = q.top().a;
//         q.pop();
//         if(vis[u]) continue;
//         vis[u] = true;
//         for(auto edge : edges[u]) {
//             int v = edge.v, w = edge.w;
//             if(dist[v] > d + w) {
//                 dist[v] = d + w;
//                 //这里应该是等于ans[u]
//                 ans[v] = ans[u];
//                 q.push({v, dist[v], ans[v]});
//             } else if(dist[v] == d + w) {
//                 ans[v] = (ans[v] + ans[u]) % MOD;
//                 ans[v] %= MOD;
//             }
//         }
//     }

// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     //此题数据量较大，建议用dijkstra
//     int n, m;
//     cin >> n >> m;
//     vis.resize(n+1, false);
//     edges.resize(n+1);
//     dist.resize(n+1, INF);
//     ans.resize(n+1, 0);
//     for(int i = 0;i < m;i++) {
//         int x, y;
//         cin >> x >> y;
//         edges[x].push_back({y, 1});
//         edges[y].push_back({x, 1});
//         // if(x == 1) {
//         //     // ans[y]++;
//         //     // ans[y] %= MOD;
//         //     dist[y] = 1;
//         // }
//         // if(y == 1) {
//         //     dist[x] = 1;
//         // }
//     }
//     ans[1] = 1;
//     dijkstra(n);
//     for(int i = 1;i <= n;i++) {
//         cout << ans[i] << '\n';
//     }
//     return 0;
// }