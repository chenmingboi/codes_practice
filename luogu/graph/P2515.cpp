#include<bits/stdc++.h>
using namespace std;

vector<int>w, value;
vector<vector<int>>edges;
vector<int>dfn, low, belong;
vector<int>scc_w, scc_v;
vector<char>instack;
stack<int>st;
int tot = 0, scc_cnt = 0;

void tarjan(int u) {
    dfn[u] = low[u] = ++tot;
    st.push(u);
    instack[u] = 1;
    for(auto v : edges[u]) {
        if(!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if(instack[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if(low[u] == dfn[u]) {
        scc_cnt++;
        int v;
        do {
            v = st.top();
            st.pop();
            belong[v] = scc_cnt;
            instack[v] = 0;
            scc_w[scc_cnt] += w[v];
            scc_v[scc_cnt] += value[v];
        } while(u != v);
    }
}

// vector<char>vis;
// vector<int>pweight, pvalue;
vector<vector<int>>dag;
vector<vector<int>>dp;

void dfs(int u, int m) {
    //初始化当前节点u
    if(u == 0) {
        //虚拟根，不占容量，价值为0
        for(int j = 0;j <= m;j++) dp[u][j] = 0;
    } else {
        //真实节点，必须选u, 初始化只选u的情况
        for(int j = scc_w[u];j <= m;j++) {
            dp[u][j] = scc_v[u];
        }
    }
    //依次合并每个子结点
    for(int v : dag[u]) {
        dfs(v, m);//递归计算子节点的dp
        //倒序枚举当前已经分配的容量, 因为下面在更新dp[u][j+k]的使用会使用dp[u][j]
        //由于每个子节点只能选择一次，所以要倒序遍历
        for(int j = m;j >= 0;j--) {
            if(dp[u][j] == INT_MIN) continue;
            //枚举分给子节点v的容量k
            for(int k = 0;j + k <= m;k++) {
                if(dp[v][k] == INT_MIN) continue;
                dp[u][j+k] = max(dp[u][j+k], dp[u][j] + dp[v][k]);
            }
        }
    }
}
// //进行dfs初始化0/1背包中的物品
// void dfs(int u, int pw, int pv) {
//     if(vis[u]) return;
//     vis[u] = 1;
//     pweight.push_back(pw);
//     pvalue.push_back(pv);
//     for(auto v : dag[u]) {
//         if(!vis[v]) {
//             pw += scc_w[v];
//             pv += scc_v[v];
//             dfs(v, pw, pv);
//             pw -= scc_w[v];
//             pv -= scc_v[v];
//         }
//     }
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    w.resize(n+1), value.resize(n+1), edges.resize(n+1);
    dfn.resize(n+1), low.resize(n+1), belong.resize(n+1);
    instack.resize(n+1, 0), scc_w.resize(n+1), scc_v.resize(n+1);
    for(int i = 1;i <= n;i++) cin >> w[i];
    for(int i = 1;i <= n;i++) cin >> value[i];
    for(int v = 1;v <= n;v++) {
        int u;
        cin >> u;
        //a依赖b，即有一条b->a的有向边，表示安装过b之后才能到达a
        if(u != 0) edges[u].push_back(v);
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) tarjan(i);
    }
    //构造dag，初始化indeg
    dag.resize(scc_cnt+1);
    vector<int>indeg(scc_cnt+1);
    for(int u = 1;u <= n;u++) {
        for(auto v : edges[u]) {
            if(belong[u] != belong[v]) {
                dag[belong[u]].push_back(belong[v]);
                indeg[belong[v]]++;
            }
        }
    }
    //构造虚拟源节点
    for(int i = 1;i <= scc_cnt;i++) {
        if(indeg[i] == 0) dag[0].push_back(i);
    }
    //dp[i][j]表示以i为根的子树中，必须选择软件i,且总站用量为j的时候能获得的最大价值
    dp.resize(scc_cnt+1, vector<int>(m+1, INT_MIN));
    //从虚拟选节点开始dfs
    dfs(0, m);
    cout << dp[0][m];
    //这道题不能这样做，因为如果有多个分支的话
    //就比如题目中的要求，我写的dfs会分成12，13，1这三种情况，但是还有一种情况是没有遍历到的
    //就是123全选，这是dfs不能考虑到的，所以要用到树形dp
    // vis.resize(scc_cnt+1, 0);
    // pweight.push_back(0), pvalue.push_back(0);
    // for(int i = 1;i <= scc_cnt;i++) {
    //     if(!vis[i] && indeg[i] == 0) {
    //         int pw = scc_w[i], pv = scc_v[i];
    //         dfs(i, pw, pv);
    //     }
    // }
    // int sz = pweight.size()-1;
    // //0/1背包
    // vector<int>dp(m+1, 0);
    // for(int i = 1;i <= sz;i++) {
    //     for(int j = m;j >= pweight[i];j--) {
    //         dp[j] = max(dp[j], dp[j-pweight[i]] + pvalue[i]);
    //     }
    // }
    // cout << dp[m];
    return 0;
}