#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
struct edge{
    char v;
    int w;
};
vector<vector<edge>>edges;
vector<bool>vis;
vector<int>dist;
struct node {
    int u;
    int d;
    bool operator<(const node& other) const {
        return d > other.d;
    }
};
pair<char, int> dijkstra(char s) {
    int len = 0;
    char ans;
    priority_queue<node>q;
    q.push({s, 0});
    while(!q.empty()) {
        auto [u, d] = q.top();
        q.pop();
        if(vis[u-'A']) continue;
        vis[u-'A'] = true;
        if(u >= 'A' && u < 'Z') {
            len = d;
            ans = u;
            break;
        }
        for(auto[v, w] : edges[u-'A']) {
            if(dist[v-'A'] > d + w) {
                dist[v-'A'] = d + w;
                q.push({v, dist[v-'A']});
            }
        }
    }
    return {ans, len};
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p;
    cin >> p;
    edges.resize(60);
    vis.resize(60, false);
    dist.resize(60, INF);
    for(int i = 0;i < p;i++) {
        char u, v;
        int w;
        cin >> u >> v >> w;
        edges[u-'A'].push_back({v, w});
        edges[v-'A'].push_back({u, w});
    }
    auto [ans, len] = dijkstra('Z');
    cout << ans << ' ' << len;
    return 0;
}