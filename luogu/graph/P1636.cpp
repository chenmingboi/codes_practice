#include<bits/stdc++.h>
using namespace std;

struct edge{
    int u;
    int v;
};

vector<edge>edges;
vector<int>fa;
vector<int>weight;
vector<int>du;

int findfa(int u) {
    if(u == fa[u]) return u;
    return fa[u] = findfa(fa[u]);
}

void merge(int u, int v) {
    int fau = findfa(u), fav = findfa(v);
    if(fau == fav) return ;
    if(weight[fau] > weight[fav]) {
        fa[fav] = fau;
    } else {
        if(weight[fau] == weight[fav]) weight[fav]++;
        fa[fau] = fav;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    du.resize(n+1, 0);
    fa.resize(n+1, 0);
    weight.resize(n+1, 1);
    for(int i = 1;i <= n;i++) fa[i] = i;
    //欧拉图路径问题
    /**
     * 对于一个连通的无向图，如果奇度顶点数为 0，则可以一笔画（欧拉回路），需要 1 笔。
    如果奇度顶点数为 odd（odd 必为偶数），则需要 odd / 2 笔。
    对于不连通的图，每个有边的连通分量独立计算，最后相加。
     */
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        du[a]++;du[b]++;
        merge(a, b);
    }
    vector<bool>hasedge(n+1, false);
    //连通图中的奇数度数点的数量
    vector<int>odd(n+1, 0);
    for(int i = 1;i <= n;i++) {
        int fai = findfa(i);
        if(du[i] > 0) hasedge[fai] = true;
        if(du[i] % 2 != 0) odd[fai]++;
    }
    int ans = 0;
    for(int i = 1;i <= n;i++) {
        //找每个连通图的代表
        if(i == findfa(i) && hasedge[i]) {
            if(odd[i] == 0) {
                ans++;
            } else {
                ans += odd[i]/2;
            }
        }
    }
    cout << ans;
    return 0;
}