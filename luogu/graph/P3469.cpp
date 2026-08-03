#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<vector<int>>edges;
vector<int>dfn, low;
vector<ll> sz, ans;
vector<char>flag;
int tot = 0;
int n, m;

void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tot;
    sz[u] = 1;
    ll sum = 0;
    int child = 0;
    for(const auto& v : edges[u]) {
        if(!dfn[v]) {
            child++;
            tarjan(v, u);
            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);
            //这里有错误，考虑只有三个节点，2->1<-3，此时1是割点，但是不会在这个循环里面更新
            //而是会在下面那个判断根节点的判断中更新
            // if(fa != u && low[v] >= dfn[u] && !flag[u]) {
            //     flag[u] = true;
            //     ans[u] += (ll)sz[v] * (n - sz[v]);
            //     //这里的sum记录的是割点对应的子树的总大小之和
            //     //区分与sz[u]因为sz[u]这里的u可能不是割点
            //     sum += sz[v];
            // }
            // if(low[v] >= dfn[u] && !flag[u]) {
            if(low[v] >= dfn[u]) {
                //添加上已经分割好的连通分量
                //这里要求u是不是根节点都要进行更新ans[u]
                //并且不能在判断条件中添加!flag[u]，这样可能会出现判断这个点是割点之后
                //它的子树并没有遍历完，此时会少算
                //循环里面判断割点的时候!flag[u]只是在计算割点数量的时候防止重复计算的一个判断条件
                ans[u] += (ll)sz[v] * (n-sz[v]);
                sum += sz[v];
                //对于根节点，只要是child数目大于1它就是割点
                //对于非根节点，只要其low[v] >= dfn[u]它就是割点
                if(u != fa || child > 1) flag[u] = true;
            }
        } else if(v != fa) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    // if(fa == u && child >= 2 && !flag[u]) {
    //     flag[u] = true;
    //     // ans[u] += 
    // }
    //如果不是割点的情况
    if(!flag[u]) {
        ans[u] = 2*(n-1);
    } else {
        ans[u] += (n-1) + (ll)(n-sum-1) * (sum+1);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    edges.resize(n+1), dfn.resize(n+1), low.resize(n+1);
    sz.resize(n+1, 0), ans.resize(n+1), flag.resize(n+1, 0);
    for(int i = 0;i < m;i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    tarjan(1, 1);
    for(int i = 1;i <= n;i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}