#include<bits/stdc++.h>
using namespace std;

const int LOG = 20;
vector<vector<int>>fa;
vector<vector<int>>edges;
vector<int>depth;

void dfs(int u, int father) {
    //先更新当前节点u的相关信息
    depth[u] = depth[father]+1;
    fa[u][0] = father;
    for(int j = 1;j <= LOG;j++) {
        //fa[u][j]表示从节点u调2^j步到达的父节点
        //等于从u先跳2^(j-1)然后再跳2^(j-1)步
        //这里不用担心跳过了，因为设置了哨兵节点0，fa[0]的所有元素均为0
        //而fa[s][0] = 0,即根节点的父节点设置为节点0，然后因为所有节点都能跳到根节点
        //跳过根节点之后就会一直为0
        fa[u][j] = fa[fa[u][j-1]][j-1];
    }
    //递归u的子节点
    for(auto v : edges[u]) {
        //因为是无向边，所以要防止回到父节点
        if(v == father) continue;
        dfs(v, u);
    }
}

int lca(int u, int v) {
    if(u == v) return u;
    //让u成为比较深的节点(让v也可以)
    if(depth[u] < depth[v]) swap(u, v);
    //先让深度比较深的跳, 直至u和v的深度一样
    //这里可以保证循环结束之后depth[u] = depth[v]
    //因为假设u 和 v的深度差为 w 则w 可以用二进制表示
    //例如相差10 则10可以用二进制表示为1010即先跳2^3再跳2^1
    for(int i = LOG;i >= 0;i--) {
        if(depth[fa[u][i]] >= depth[v]) {
            u = fa[u][i];
        }
    }
    //u和v的深度一样了
    //如果u 和v 是在同一分支上，即v是u的父节点（这里不单止最近的父节点
    //只要是depth小于u且u能够单向向上到达）
    if(u == v) return u;
    //如果是在两个分支上, 两个节点一起跳
    for(int j = LOG;j >= 0;j--) {
        //如果跳到fa[u][j]] == fa[v][j]表明跳的多了
        //跳到了lca的上面或者刚好是lca
        //如果跳到了不相等，说明跳在了lca的下面，此时可以一起跳
        //和上面u跳的原理一样，如果depth[u]和depth[v]和depth[lca(u, v)]相差10
        //那么如果跳的步数大于10那么就会fa相同，如果小于10fa就会不同
        //由于10可以表示成1010(2)所以会先跳8步，然后尝试6步（已经累计14步了）发现fa相同，不跳
        //然后尝试4步，依然不跳，尝试2步已让不跳，尝试1步，此时累计跳9步，没到lca，fa不相同，可以跳
        //然后跳最小的一步就会使得fa相同，所以结束循环
        //结束循环的时候一定是u和v处于lca(u, v)的最直接的子节点
        //其实就是跳depth[u]-depth[lca(u, v)]-1（注意这里减一）(必然可以用二进制表示)
        //最终只需要再跳一步就可以到lca(u, v)
        // if(depth[fa[u][j]] != depth[fa[v][j]]) {
        //注意这里比较的是fa而不是depth[fa]因为现在u和v的深度已经相同
        //再往上跳相同的步数depth依然会相同，就不会更新u,v，我们比较的是fa的节点编号
        if(fa[u][j] != fa[v][j]) {
            u = fa[u][j], v = fa[v][j];
        }
    }
    //所以最终返回的是还要再跳一步的结果
    return fa[u][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    fa.resize(n+1, vector<int>(LOG+1, 0));
    edges.resize(n+1);
    depth.resize(n+1, 0);
    for(int i = 0;i < n-1;i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    dfs(s, 0);//从根节点开始遍历，这里设置哨兵节点0，fa[0]的所有元素均为0
    while(m) {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << endl;
        m--;
    }
    return 0;
}