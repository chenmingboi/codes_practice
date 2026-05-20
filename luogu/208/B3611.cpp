#include<bits/stdc++.h>
using namespace std;

//针对可到达到性，其实更推荐的写法是floyd

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<bool>>reach(n+1, vector<bool>(n+1, false));
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int a;
            cin >> a;
            if(a) reach[i][j] = true;
        }
    }
    for(int k = 1;k <= n;k++) {
        for(int i = 1;i <= n;i++) {
            for(int j = 1;j <= n;j++) {
                if(reach[i][k] && reach[k][j])
                    reach[i][j] = true;
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            if(reach[i][j]) {
                cout << 1 << ' ';
            } else {
                cout << 0 << ' ';
            }
        }
        cout << '\n';
    }
    return 0;
}
// const int INF = 0x3f3f3f3f;
// struct Edge {
//     int v;
//     int w;
// };

// struct Node {
//     int dist;
//     int u;
//     bool operator>(const Node& other) const { return dist > other.dist; }
// };

// vector<vector<Edge>>edges;
// vector<int>dist;
// vector<bool>visited;

// //dijkstra
// bool dijkstra(int n, int s) {
//     //小顶堆
//     priority_queue<Node, vector<Node>, greater<Node>>q;
//     q.push({0, s});
//     dist[s] = 0;
//     bool result = false;
//     while(!q.empty()) {
//         int u = q.top().u;
//         int du = q.top().dist;
//         q.pop();
//         if(visited[u]) continue;
//         for(auto edge : edges[u]) {
//             int v = edge.v, w = edge.w;
//             if(v == s) result = true;
//             if(dist[v] > dist[u] + w) {
//                 dist[v] = dist[u] + w;
//                 q.push({dist[v], v});
//             }
//         }
//         visited[u] = true;
//     }
//     return result;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     edges.resize(n+1);
//     for(int i = 1;i <= n;i++) {
//         for(int j = 1;j <= n;j++) {
//             int bian;
//             cin >> bian;
//             if(bian) {
//                 edges[i].push_back({j, 1});
//             }
//         }
//     }
//     for(int i = 1;i <= n;i++) {
//         //
//         dist.assign(n+1, INF);
//         visited.assign(n+1, false);
//         bool huan = dijkstra(n, i);
//         for(int j = 1;j <= n;j++) {
//             //这里要添加通过外环能够到自身的节点输出也为1
//             if(i == j && huan) {
//                 cout << 1 << ' ';
//             } else if(i == j && !huan) {
//                 cout << 0 << ' ';
//             } else if(dist[j] != INF) {
//                 cout << 1 << ' ';
//             } else {
//                 cout << 0 << ' ';
//             }
//         }
//         cout << '\n';
//     }
//     return 0;
// }