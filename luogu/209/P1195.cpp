#include<bits/stdc++.h>
using namespace std;

struct Edge{
    int u;
    int v;
    int w;
};

vector<Edge>edges;
vector<int>fa;
vector<int>weight;

bool comp(const Edge& a, const Edge& b) {
    return a.w < b.w;
}

int findFa(int u) {
    return ((u == fa[u]) ? fa[u] : (fa[u] = findFa(fa[u])));
}

bool merge(int u, int v) {
    int fau = findFa(u), fav = findFa(v);
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

int kruskal(int n, int k) {
    sort(edges.begin(), edges.end(), comp);
    int ans = 0;
    int cnt = n;
    for(const auto& edge : edges) {
        int u = edge.u, v = edge.v, w = edge.w;
        if(k == cnt) break;
        if(merge(u, v)) {
            cnt--;
            ans += w;
        }
    }
    if(k == cnt) {
        return ans;
    } else {
        return -1;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    fa.resize(n+1), weight.resize(n+1, 1), edges.resize(m);
    for(int i = 1;i <= n;i++) {
        fa[i] = i;
    }
    for(int i = 0;i < m;i++) {
        int x, y, l;
        cin >> x >> y >> l;
        edges[i] = {x, y, l};
    }
    int ans = kruskal(n, k);
    if(ans == -1) {
        cout << "No Answer";
    } else {
        cout << ans;
    }
    return 0;
}