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
//判断负环存在用bellman_ford算法
bool bellman_ford(int n, int s) {
    dist[s] = 0;
    bool flag = false;
    for(int i = 1;i <= n;i++) {
        //循环n次
        flag = false;
        for(auto edge : edges) {
            int u = edge.u, v = edge.v, w = edge.w;
            if(dist[u] == INF) continue;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                flag = true;
            }
        }
        if(!flag) break;
    }
    return flag;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        dist.assign(n+1, INF);
        for(int i = 0;i < m;i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if(w >= 0) {
                edges.push_back({v, u, w});
            }
            edges.push_back({u, v, w});
        }
        if(bellman_ford(n, 1)) {
            cout << "YES" << '\n';
        } else {
            cout << "NO" << '\n';
        }
        edges.clear();
    }
    return 0;
}