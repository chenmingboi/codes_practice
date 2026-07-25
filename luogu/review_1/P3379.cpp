#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
//fa[i][j]表示i节点向上2^j步的祖先
vector<vector<int>>fa;
vector<int>depth;

void buildTree(int s, int last) {
    fa[s][0] = last;
    depth[s] = depth[last]+1;
    for(int i = 1;i <= 20;i++) {
        fa[s][i] = fa[fa[s][i-1]][i-1];
    } 
    for(auto v : edges[s]) {
        if(v != last) buildTree(v, s);
    }
}

int query(int a, int b) {
    if(a == b || fa[b][0] == a) return a;
    if(fa[a][0] == b) return b;
    if(depth[a] < depth[b]) swap(a, b);
    //depth[a] >= depth[b]
    if(depth[a] != depth[b]) {
        int dif = depth[a] - depth[b];
        int i = 0;
        while(dif) {
            if(dif & 1) {
                a = fa[a][i];
            }
            dif = dif >> 1;
            i++;
        }
    }
    //depth[a] = depth[b]
    //在同一侧
    if(a == b) return a;
    //在不同侧，一起再往上跳
    for(int i = 20;i >= 0;i--) {
        if(fa[a][i] != fa[b][i]) {
            a = fa[a][i], b = fa[b][i];
        }
    }
    //现在fa[a][0] = fa[b][0]
    return fa[a][0];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    edges.resize(n+1);
    fa.resize(n+1, vector<int>(21));
    depth.resize(n+1);
    depth[0] = 0;
    for(int i = 0;i < n-1;i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    buildTree(s, 0);
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        cout << query(a, b) << '\n';
    }
    return 0;
}