#include<bits/stdc++.h>
using namespace std;

int n, total_weight = 0;
//数组设置意义和P1395相同
vector<vector<int>>edges;
vector<int>sz;
vector<int>weight;
vector<long long>dp;

//初始化dp[1]和更新sz
void dfs1(int u, int father, int depth) {
    dp[1] += depth * weight[u];
    for(auto v : edges[u]) {
        if(v == father) continue;
        dfs1(v, u, depth+1);
        sz[u] += sz[v];
    }
}

void dfs2(int u, int father) {
    for(auto v : edges[u]) {
        if(v == father) continue;
        //状态转移公式
        //不同于P1395中的dp[v] = dp[u] + n - 2LL*sz[v]
        //这里如果将u转移到v,是除了sz[v]之外的所有节点的权重到目的地都增加1
        //所以应该是增加total_weight - sz[v],然后还是减少sz[v]
        //注意这里是权重之和
        dp[v] = dp[u] + total_weight - 2LL*sz[v];
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //此题相对于P1395 会议来说多了节点的权重
    //增加weight数组记录节点的权重，sz数组更新时要注意是增加子树所有节点的权重
    cin >> n;
    edges.resize(n+1), sz.resize(n+1);
    dp.resize(n+1), weight.resize(n+1);
    for(int i = 1;i <= n;i++) {
        int w, u, v;
        cin >> w >> u >> v;
        //初始化节点i的权重
        weight[i] = w, sz[i] = w;
        total_weight += w;
        if(u != 0) {
            edges[i].push_back(u);
            edges[u].push_back(i);
        }
        if(v != 0) {
            edges[i].push_back(v);
            edges[v].push_back(i);
        }
    }
    dfs1(1, 0, 0);
    dfs2(1, 0);
    long long ans = dp[1];
    for(int i = 2;i <= n;i++) {
        if(dp[i] < ans) ans = dp[i];
    }
    cout << ans;
}