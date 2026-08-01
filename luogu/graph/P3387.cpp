#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>dfn, low, belong;//belong是指节点属于哪个强连通分量
vector<char>instack;
vector<int>weight;
vector<int>a;
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
    if(dfn[u] == low[u]) {
        scc_cnt++;
        int v;
        do{
            v = st.top();
            st.pop();
            instack[v] = 0;
            belong[v] = scc_cnt;
            weight[scc_cnt] += a[v];
        } while(u != v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1), belong.resize(n+1), dfn.resize(n+1);
    low.resize(n+1), instack.resize(n+1, 0), weight.resize(n+1);
    a.resize(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) tarjan(i);
    }
    //将原来图中每个连通分量压缩成一个节点
    vector<vector<int>>dag(scc_cnt+1);
    vector<int>indeg(scc_cnt+1);//新图中节点的入度
    vector<int>dp(scc_cnt+1);
    //建新图
    for(int u = 1;u <= n;u++) {
        for(auto v : edges[u]) {
            if(belong[u] != belong[v]) {
                dag[belong[u]].push_back(belong[v]);
                indeg[belong[v]]++;
            }
        }
    }
    //拓扑排序+DP
    queue<int>q;
    for(int i = 1;i <= scc_cnt;i++) {
        if(indeg[i] == 0) {
            q.push(i);
            dp[i] = weight[i];
        }
    }
    int ans = 0;
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        ans = max(ans, dp[u]);
        for(auto v : dag[u]) {
            if(indeg[v]) {
                dp[v] = max(dp[v], dp[u] + weight[v]);
                indeg[v]--;
                if(indeg[v] == 0) {
                    q.push(v);
                }
            }
        }
    }
    cout << ans;
    return 0;
}