#include<bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>>edges;
vector<int>depth;
//fa[i][j]表示i节点跳2^j步之后达到的父节点
vector<vector<int>>fa;

//初始化depth
void dfs(int u, int father) {
    depth[u] = depth[father] + 1;
    fa[u][0] = father;
    for(int i = 1;i <= LOG;i++) {
        //fa[u][i] 等于u先跳2^(j-1)步然后再跳2^(j-1)步
        fa[u][i] = fa[fa[u][i-1]][i-1];
    }
    for(auto v : edges[u]) {
        if(v == father) continue;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if(a == b || fa[b][0] == a) return a;
    if(fa[a][0] == b) return b;
    //将a 设为深度较深的节点
    if(depth[a] < depth[b]) swap(a, b);
    //注意这里是从大到小遍历尝试跳，因为如果从小达到凑不出来中间有0的二进制数
    for(int i = LOG;i >= 0;i--) {
        if(depth[fa[a][i]] >= depth[b]){
            a = fa[a][i];
        }
    }
    //现在depth[a] = depth[b]
    //1. 如果在同分支上
    if(a == b) return a;
    //2.在不同分支上，一起往上跳
    for(int i = LOG;i >= 0;i--) {
        if(fa[a][i] != fa[b][i]) {
            a = fa[a][i], b = fa[b][i];
        }
    }
    //现在fa[a][0] = fa[b][0];
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
    for(int i = 0;i < n-1;i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    fa[0][0] = 0;//哨兵节点
    depth[0] = 0;
    dfs(s, 0);
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }
    return 0;
}