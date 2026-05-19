#include<bits/stdc++.h>
using namespace std;

int n;
vector<vector<pair<int, int>>>edges;
vector<int>sz; //存储子树大小

struct Edge {
    int u;
    int v;
    int w;
};
//初始化sz
void dfs1(int u, int father) {
    sz[u] = 1;
    for(auto v : edges[u]) {
        if(v.first == father) continue;
        dfs1(v.first, u);
        sz[u] += sz[v.first];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //题目的费用计算方式是：对于最终方案里的每一条道路，
    //假设把这条道路拆掉，看整棵树被分成哪两部分
    //而不是在修建的过程中看还没有修好的道路两边国家都有多少
    //这道题答案是固定的，而不是让修建的顺序，然后求最小的费用
    cin >> n;
    vector<int>edges_cnt(n+1);
    vector<Edge>edge;
    edges.resize(n+1), sz.resize(n+1);
    for(int i = 0;i < n-1;i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edges_cnt[a]++, edges_cnt[b]++;
        edges[a].push_back({b, c});
        edges[b].push_back({a, c});
        edge.push_back({a, b, c});
    }
    int root = 1;
    for(int i = 2;i <= n;i++) {
        if(edges_cnt[i] > edges_cnt[root]) root = i;
    }
    //选取边数最多的节点当root
    dfs1(root, 0);
    long long ans = 0;
    for(auto it : edge) {
        //这里要减去比较小的即远离根节点的sz
        int s = min(sz[it.u], sz[it.v]);
        //注意这里前面要加1LL要不然还是int没有转换为long long
        ans += 1LL * it.w * abs(n - s - s);
    }
    cout << ans;
    return 0;
}