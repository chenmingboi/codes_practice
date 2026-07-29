// #include<bits/stdc++.h>
// using namespace std;

// struct edge{
//     int u;
//     int v;
//     int w;
// };

// bool comp(const edge& a, const edge& b) {
//     return a.w < b.w;
// }

// vector<edge>edges;
// vector<int>fa;
// vector<int>weight;

// int findFa(int u) {
//     if(u == fa[u]) return u;
//     return fa[u] = findFa(fa[u]);
// }

// bool merge(int u, int v) {
//     int fau = findFa(u), fav= findFa(v);
//     if(fau == fav) return false;
//     if(weight[fau] > weight[fav]) {
//         fa[fav] = fau;
//     } else {
//         if(weight[fau] == weight[fav]) weight[fav]++;
//         fa[fau] = fav;
//     }
//     return true;
// }

// int kruskal(int n) {
//     sort(edges.begin(), edges.end(), comp);
//     int cnt = 0;
//     int ans = -1;
//     for(int i = 0;i < n-1;i++) {
//         for(auto [u, v, w] : edges) {
//             if(merge(u, v)) {
//                 cnt++;
//                 ans = max(ans, w);
//             }
//         }
//         if(cnt == n-1) break;
//     }
//     return ans;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     //最小生成树中最长的边也就是最后一条加入的边
//     int n, m;
//     cin >> n >> m;
//     fa.resize(n+1), weight.resize(n+1, 0);
//     for(int i = 1;i <= n;i++) fa[i] = i;
//     for(int i = 0;i < m;i++) {
//         int u, v, w;
//         cin >> u >> v >> w;
//         edges.push_back({u, v, w});
//     }
//     cout << kruskal(n);
//     return 0;
// }


#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

struct edge{
    int v;
    int w;
};

struct node {
    int u;
    int d;
    bool operator<(const node& other) const {
        return d > other.d;
    }
};

vector<vector<edge>>edges;
vector<bool>inTree;
//这里的dist用于记录所有到达节点i的边的最小权重，同时用于筛选和优化那些后来加入
//且边的权重比较大的不在进入q进入循环从而减少时间
vector<int>dist;

int prim(int n) {
    int cnt = 0;
    int ans = 0;
    priority_queue<node>q;
    dist[1] = 0;
    q.push({1, dist[1]});
    while(!q.empty() && cnt < n) {
        auto [u, d] = q.top();
        q.pop();
        if(inTree[u]) continue;
        inTree[u] = true;
        ans = max(ans ,d);
        cnt++;
        for(auto [v, w] : edges[u]) {
            if(!inTree[v] && dist[v] > w) {
                dist[v] = w;
                q.push({v, w});
            }
        }
    }
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1), inTree.resize(n+1, false);
    dist.resize(n+1, INF);
    for(int i = 0;i < m;i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges[u].push_back({v, w});
        edges[v].push_back({u, w});
    }
    cout << prim(n);
    return 0;
}