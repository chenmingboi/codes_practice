#include<bits/stdc++.h>
using namespace std;

//prime
const int INF = 0x3f3f3f3f;

struct Edge{
    int v;
    int w;
};

struct Node{
    int u;
    int d;
    //这里的d表示的是u的所有邻居到u的最小距离
    bool operator<(const Node& other) const {
        return d > other.d;
    }
};

vector<vector<Edge>>edges;
vector<int>dist;
vector<bool>inTree;

int prime(int n) {
    priority_queue<Node>q;
    dist[1] = 0;
    q.push({1, dist[1]});
    int ans = 0, cnt = 0;
    while(!q.empty()) {
        if(cnt == n) break;
        auto [u, d] = q.top();
        q.pop();
        if(inTree[u]) continue;
        inTree[u] = true;
        cnt++;
        ans += d;
        for(auto [v, w] : edges[u]) {
            if(dist[v] > w) {
                dist[v] = w;
                q.push({v, dist[v]});
            }
        }
    }
    if(cnt != n) return -1;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1);
    inTree.resize(n+1, false);
    dist.resize(n+1, INF);
    for(int i = 0;i < m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back({y, z});
        edges[y].push_back({x, z});
    }
    int ans = prime(n);
    if(ans == -1) {
        cout << "orz";
    } else {
        cout << ans;
    }
    return 0;
}








//kruskal
// struct Edge{
//     int u;
//     int v;
//     int w;
// };

// vector<Edge>edges;
// vector<int>fa;
// vector<int>weight;

// bool comp(const Edge& a, const Edge& b) {
//     return a.w < b.w;
// }

// int findFa(int u) {
//     if(u == fa[u]) return fa[u];
//     return fa[u] = findFa(fa[u]);
// }

// bool merge(int u, int v) {
//     int fau = findFa(u), fav = findFa(v);
//     if(fau == fav) return false;
//     int wu = weight[fau], wv = weight[fav];
//     if(wu > wv) {
//         fa[fav] = fau;
//     } else {
//         if(wu == wv) {
//             weight[fav]++;
//         }
//         fa[fau] = fav;
//     }
//     return true;
// }

// int kruskal(int n) {
//     sort(edges.begin(), edges.end(), comp);
//     int ans = 0, cnt = 0;
//     for(int i = 0;i < n;i++) {
//         if(cnt == n-1) break;
//         for(auto [u, v, w] : edges) {
//             if(merge(u, v)) {
//                 cnt++;
//                 ans += w;
//             }
//         }
//     }
//     if(cnt != n-1) return -1;
//     return ans;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     fa.resize(n+1);
//     weight.resize(n+1, 1);
//     for(int i = 0;i < m;i++) {
//         int x, y, z;
//         cin >> x >> y >> z;
//         edges.push_back({x, y, z});
//         edges.push_back({y, x, z});
//     }
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     int ans = kruskal(n);
//     if(ans == -1) {
//         cout << "orz";
//     } else {
//         cout << ans;
//     }
//     return 0;
// }