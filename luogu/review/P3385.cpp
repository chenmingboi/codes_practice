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

bool bellman_ford(int n) {
    dist[1] = 0;
    bool flag = false;
    for(int i = 1;i <= n;i++) {
        flag = false;
        for(auto edge : edges) {
            int u = edge.u, v = edge.v, w = edge.w;
            if(dist[u] != INF && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                flag = true;
            }
        }
        if(!flag) break;
    }
    if(flag) return true;
    return false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        edges.resize(m);
        
        for(int i = 0;i < m;i++) {
            int u, v, w;
            cin >> u >> v >> w;
            if(w >= 0) {
                
            }
        }
    }
}