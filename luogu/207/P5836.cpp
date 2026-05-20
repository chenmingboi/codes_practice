#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>fa;
vector<int>weight;
vector<char>kind;
vector<bool>visited;

int find_fa(int u) {
    if(u == fa[u]) return u;
    return fa[u] = find_fa(fa[u]);
}

void merge(int u, int v) {
    int fau = find_fa(u), fav = find_fa(v);
    if(fau == fav) return;
    //把weight小的合并到weight大的中
    if(weight[fau] >= weight[fav]) {
        fa[fav] = fau;
        //weight相等的时候要加，weight可以想想成为最深的深度，加入一个没那么深的子树
        //不会影响最深的深度
        if(weight[fau] == weight[fav]) {
            weight[fau]++;
        }
    } else {
        fa[fau] = fav;
    }
}

//
void bfs(int u) {
    queue<int>q;
    q.push(u);
    visited[u] = true;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : edges[u]) {
            if(visited[v]) continue;
            if(kind[v] == kind[u]) {
                q.push(v);
                visited[v] = true;
                //划分同品种的联通块
                merge(u, v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1), fa.resize(n+1), kind.resize(n+1);
    visited.resize(n+1, false), weight.resize(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> kind[i];
        fa[i] = i;
        weight[i] = 1;
    }
    for(int i = 0;i < n-1;i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for(int i = 1;i <= n;i++) {
        if(!visited[i]) {
            bfs(i);
        }
    }
    for(int i = 0;i < m;i++) {
        int a, b;
        char c;
        cin >> a >> b >> c;
        int faa = find_fa(a), fab = find_fa(b);
        //这里判断条件写错了，当faa != fab且kind[faa] 和 kind[fab]相同不等于c的时候
        //表明从a到b的时候一定会通过kind=c的联通块，因为是kind=c的联通块把faa和fab这两个不等于c
        //的联通块给隔离开了
        //判断条件为，如果a和b在两个不同的联通块中，那么路径中一定包含H和G
        //如果a和b在同一个联通块中的时候只需判断kind[faa]是否等于c
        if(faa != fab || kind[faa] == c) {
            cout << 1;
        } else {
            cout << 0;
        }
    }
}