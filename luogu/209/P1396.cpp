#include<bits/stdc++.h>
using namespace std;

//从最小生成树中寻找路径？

struct Edge{
    int u;
    int v;
    int w;
};

vector<int>fa, weight;
vector<Edge>edges;

bool comp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int find_fa(int u) {
    return ((u == fa[u]) ? fa[u] : (fa[u] = find_fa(fa[u])));
}

bool merge(int u, int v) {
    int fau = find_fa(u), fav = find_fa(v);
    if(fau == fav) return false;
    if(weight[fau] < weight[fav]) {
        fa[fau] = fav;
    } else {
        if(weight[fau] == weight[fav]) {
            weight[fau]++;
        }
        fa[fav] = fau;
    }
    return true;
}

int kruskal(int s, int t) {
    sort(edges.begin(), edges.end(), comp);
    int ans = 0;
    for(const auto& edge : edges) {
        int u = edge.u, v = edge.v, w = edge.w;
        if(merge(u, v)) {
            //因此可以简化为 ans = w; 因为w是递增的，后续的w肯定会覆盖前面的值
            // ans = max(ans, w);
            ans = w;
            //s和t处于同一连通块了
            //一旦 s 和 t 第一次连通，当前这条边的权值就是答案。
            if(find_fa(s) == find_fa(t)) break;
        }
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    edges.resize(m), fa.resize(n+1), weight.resize(n+1, 1);
    for(int i = 1;i <= n;i++) fa[i] = i;
    for(int i = 0;i < m;i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    cout << kruskal(s, t);
    return 0;
}