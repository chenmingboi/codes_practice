#include<bits/stdc++.h>
using namespace std;


const int INF = 0x3f3f3f3f;
const int no = pow(2, 31) - 1;

//floyd
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<vector<int>>dist(n+1, vector<int>(n+1, INF));
    for(int i = 1;i <= n;i++) dist[i][i] = 0;
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = min(dist[u][v], w);
    }
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        if(dist[s][i] != INF) {
            cout << dist[s][i] << ' ';
        } else {
            cout << no << ' ';
        }
    }
    return 0;
}
// //bellman_ford
// struct Edge{
//     int u;
//     int v;
//     int w;
// };

// vector<Edge>edges;
// vector<int>dist;

// void bellman_ford(int s, int n) {
//     dist[s] = 0;
//     bool flag = false;
//     //此题不用判断负环所以n-1次循环就行
//     for(int i = 1;i <= n-1;i++) {
//         flag = false;
//         for(auto edge : edges) {
//             int u = edge.u, v = edge.v, w = edge.w;
//             if(dist[u] != INF && dist[v] > dist[u] + w) {
//                 dist[v] = min(dist[v], dist[u] + w);
//                 flag = true;
//             }
//         }
//         if(!flag) break;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m, s;
//     cin >> n >> m >> s;
//     edges.resize(m);
//     dist.resize(n+1, INF);
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges[i] = {u, v, w};
//     }
//     bellman_ford(s, n);
//     for(int i = 1;i <= n;i++) {
//         cout << ((dist[i] == INF) ? no : dist[i]) << ' ';
//     }
//     return 0;
// }

//dijkstra
// struct Edge{
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
// vector<bool>vis;
// vector<int>dist;

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
//     for(int i = 1;i <= n;i++) {
//         if(dist[i] != INF) {
//             cout << dist[i] << ' ';
//         } else {
//             cout << no << ' ';
//         }
//     }
//     return 0;
// }



// #include<bits/stdc++.h>
// using namespace std;

// const int INF = 0x3f3f3f3f;
// const int no = pow(2, 31) - 1;


// //floyd

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m, s;
//     cin >> n >> m >> s;
//     vector<vector<int>>dist(n+1, vector<int>(n+1, INF));
//     for(int i = 1;i <= n;i++) dist[i][i] = 0;
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         //这里要取min，因为题目中说两点之间可能会有多条边
//         //这里要求其中的最小一条边
//         dist[u][v] = min(dist[u][v], w);
//     }
//     //注意floyd中k是在最外层，使用
//     //用前 k - 1 个点已经更新好的结果，去推出允许使用前 k 个点后的结果
//     for(int k = 1;k <= n;k++) {
//         for(int i = 1;i <= n;i++) {
//             for(int j = 1;j <= n;j++) {
//                 if(dist[i][k] != INF && dist[k][j] != INF) {
//                     dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
//                 }
//             }
//         }
//     }
//     for(int i = 1;i <= n;i++) {
//         if(dist[s][i] != INF) {
//             cout << dist[s][i] << ' ';
//         } else {
//             cout << no << ' ';
//         }
//     }
//     return 0;
// }
// //bellman_ford
// struct Edge {
//     int u;
//     int v;
//     int w;
// };

// bool comp(const Edge& a, const Edge& b) {
//     return a.w < b.w;
// }

// vector<int>dist;
// vector<bool>vis;
// vector<Edge>edges;

// void bellman_ford(int s, int n) {
//     dist[s] = 0;
//     int cishu = 0;
//     sort(edges.begin(), edges.end(), comp);
//     // while(true) { //其实这里不要用while ture
//     for(int i = 1;i <= n;i++) {
//         //用for循环限定次数更好
//         //这里看题目要求是什么吧，如果是让求有没有负环
//         //这个条件就不要加，因为负环的判断条件是看第n个循环还有没有更新
//         //因为如果不存在负环，第n次就不会更新，但是如果有的话，第n次会更新
//         //所以可以将flag的值作为返回值来判定图里面有没有负环
//         if(cishu == n-1) break;
//         //因为题目中不保证是连通图，所以添加flag
//         //因为当不是连通图的时候更新cishu就不会到n-1
//         //此时通过看flag是否变为true来break掉循环
//         //防止死循环
//         bool flag = false;
//         for(auto edge : edges) {
//             int u = edge.u, v = edge.v, w = edge.w;
//             if(dist[u] != INF && dist[v] > dist[u] + w) {
//                 dist[v] = dist[u] + w;
//                 cishu++;
//                 flag = true;
//             }
//         }
//         if(!flag) break;
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m, s;
//     cin >> n >> m >> s;
//     edges.resize(m), dist.resize(n+1, INF), vis.resize(n+1, false);
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges[i] = {u, v, w};
//     }
//     bellman_ford(s, n);
//     for(int i = 1;i <= n;i++) {
//         if(dist[i] != INF) {
//             cout << dist[i] << ' ';
//         } else {
//             cout << no << ' ';
//         }
//     }
//     return 0;
// }
// //dijkstra
// struct Edge{
//     int v;
//     int w;
// };

// //这里的d表示的是从题目中标定的源节点到该节点的最小距离
// struct Node {
//     int u;
//     int d;
//     bool operator>(const Node& other) const {
//         return this->d > other.d;
//     }
// };

// vector<vector<Edge>>edges;
// vector<int>dist;
// vector<bool>vis;

// void dijkstra(int s, int n) {
//     priority_queue<Node, vector<Node>, greater<Node>> q;
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
//     edges.resize(n+1), dist.resize(n+1, INF),
//     vis.resize(n+1, false);
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges[u].push_back({v, w});
//     }
//     dijkstra(s, n);
//     for(int i = 1;i <= n;i++) {
//         if(dist[i] != INF) {
//             cout << dist[i] << ' ';
//         } else {
//             cout << no << ' ';
//         }
//     }
//     return 0;
// }