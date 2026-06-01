#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>weight;
vector<int>dp;
int totalweight;

void dfs1(int u, int fa, int depth) {
    dp[1] += depth * weight[u];
    for(auto v : edges[u]) {
        if(v != fa) {
            dfs1(v, u, depth+1);
            weight[u] += weight[v];
        }
    }
}

//更新dp
void dfs2(int u, int fa) {
    for(auto v : edges[u]) {
        if(v != fa) {
            dp[v] = dp[u] + totalweight - weight[v] - weight[v];
            dfs2(v, u);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //假设以1为根时距离和为dp[1]
    //当以3为根时 dp[3] = dp[1] + weight[1].left - weight[1].right
    //其中weight[1].right = totalweight - weight[1].left
    //weight[i]定义为以i为根的子树的totalweight
    int n;
    cin >> n;
    edges.resize(n+1);
    weight.resize(n+1, 0);
    dp.resize(n+1, 0);
    for(int i = 1;i <= n;i++) {
        int w, u, v;
        cin >> w >> u >> v;
        weight[i] = w;
        totalweight += w;
        if(u != 0) {
            edges[i].push_back(u);
            edges[u].push_back(i);
        }
        if(v != 0) {
            edges[i].push_back(v);
            edges[v].push_back(i);
        }
    }
    //这里随便选择一个节点都可以
    dfs1(1, 1, 0);
    dfs2(1, 1);
    int ans = INT_MAX;
    for(int i = 1;i <= n;i++) {
        ans = min(ans, dp[i]);
    }
    cout << ans;
    return 0;
}