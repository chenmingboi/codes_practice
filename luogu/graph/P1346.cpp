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

vector<vector<edge>>edges;
vector<int>dist;
vector<bool>vis;

int dijkstra(int a, int b) {
    dist[a] = 0;
    priority_queue<node>q;
    q.push({a, dist[a]});
    while(!q.empty()) {
        auto [u, d] = q.top();
        q.pop();
        if(vis[u] && u == b) break;
        if(vis[u]) continue;
        vis[u] = true;
        for(auto [v, w] : edges[u]) {
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                q.push({v, dist[v]});
            }
        }
    }
    if(dist[b] != INF) {
        return dist[b];
    } else {
        return -1;
    }
} 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    edges.resize(n+1);
    vis.resize(n+1, false);
    dist.resize(n+1, INF);
    for(int i = 1;i <= n;i++) {
        int k;
        cin >> k;
        for(int j = 0;j < k;j++) {
            int v, w;
            cin >> v;
            //通过将到相连的第一个路口通道的权重赋值为0
            //到其余路口的通道的权重赋值为1
            if(j == 0) {
                w = 0;
            } else {
                w = 1;
            }
            edges[i].push_back({v, w});
        }
    }
    cout << dijkstra(a, b);
    return 0;
}