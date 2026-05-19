#include<bits/stdc++.h>
using namespace std;

int n;

vector<vector<int>>edges;
//sz表示以该节点为根的子树大小
vector<int>sz;
//dp[i]表示以节点i做会议节点的时候其余村民到该节点时的距离和
//先算出来dp[1]，然后再根据状态转移公式得到dp[2]~dp[n]
vector<long long>dp;

void dfs1(int u, int father, int depth) {
    //dfs1用来初始化dp[1]以及sz数组
    sz[u] = 1;
    //节点1的depth = 0,针对节点1的直接子节点在for循环中执行dfs1
    //depth+1,即直接子节点到节点1的距离均为1，符合题意要求
    dp[1] += depth;
    for(auto v : edges[u]) {
        if(v == father) continue;
        dfs1(v, u, depth+1);
        sz[u] += sz[v];
    }
}

//dfs2用来更新dp数组
void dfs2(int u, int father) {
    for(auto v : edges[u]) {
        if(v == father) continue;
        //状态转移公式（核心）
        //原来如果选则父节点u为会议节点的化距离之和为dp[u]
        //现在选择v作为会议节点，则除了v之外的其他分支包括父节点u到达会议节点的路程每个节点都增加了1
        //总共有n-sz[v]个节点的路程分别增加一，
        //对于根为v的子树来说(包括v)，所有节点到达会议节点的路径都减少一，总共为sz[v]个节点
        //所以dp[v] = dp[u] + (n - sz[v]) - sz[v]
        dp[v] = dp[u] + n - 2LL * sz[v];
        dfs2(v, u);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //使用dp
    cin >> n;
    edges.resize(n+1), sz.resize(n+1), dp.resize(n+1);
    for(int i = 0;i < n-1;i++) {
        int a, b;
        cin >> a >> b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    dfs1(1, 0, 0);
    dfs2(1, 0);
    long long x, y;
    y = dp[1], x = 1;
    for(int i = 1;i <= n;i++) {
        if(dp[i] < y) {
            y = dp[i], x = i;
        }
    }
    cout << x << ' ' << y;
    return 0;
}