#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

//尝试使用dijkstra
struct Edge{
    int v;
    int w;
};

struct Node{
    int u;
    int dist;
    bool operator>(const Node& other) const { return dist > other.dist; }
};

vector<vector<Edge>>edges;
vector<bool>visited;
vector<int>dist;

void dijkstra(int s, int n) {
    priority_queue<Node, vector<Node>, greater<Node>>q;
    //这里不用初始化dist[s] = 0也可以，因为在while循环中edges是添加了自己到自己的环的，所以会更新为dist[s] = 0
    q.push({s, 0});
    while(!q.empty()) {
        int u = q.top().u;
        int d = q.top().dist;
        q.pop();
        if(visited[u]) continue;
        visited[u] = true;
        for(auto edge : edges[u]) {
            int v = edge.v, w = edge.w;
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
    vector<int>passby(m);
    for(int i = 0;i < m;i++) {
        cin >> passby[i];
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= n;j++) {
            int w;
            cin >> w;
            edges[i].push_back({j, w});
        }
    }
    long long ans = 0;
    for(int i = 0;i < m-1;i++) {
        visited.assign(n+1, false);
        dist.assign(n+1, INF);
        dijkstra(passby[i], n);
        ans += dist[passby[i+1]];
    }
    cout << ans;
    return 0;
}

// //floyd可以通过
// const int INF = 0x3f3f3f3f;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     //最终的最小值为各个分段最小值之和
//     int n, m;
//     cin >> n >> m;
//     vector<vector<int>>dist(n+1, vector<int>(n+1, INF));
//     vector<int>passby(m);
//     for(int i = 0;i < m;i++) {
//         cin >> passby[i];
//     }
//     for(int i = 1;i <= n;i++) {
//         for(int j = 1;j <= n;j++) {
//             int danger;
//             cin >> danger;
//             dist[i][j] = danger;
//         }
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
//     for(int i = 0;i < m-1;i++) {
//         ans += dist[passby[i]][passby[i+1]];
//     }
//     cout << ans;
//     return 0;
// }