#include<bits/stdc++.h>
using namespace std;

using ll = long long;
vector<vector<int>>edges;
vector<int>dfn, low, belong;
vector<char>instack;
stack<int>st;
vector<int>a;
vector<ll>scc_weight;

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
            scc_weight[scc_cnt] += a[v];
        } while(u != v);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s, p;
    cin >> n >> m;
    edges.resize(n+1), dfn.resize(n+1), low.resize(n+1);
    belong.resize(n+1), instack.resize(n+1, 0), a.resize(n+1);
    vector<char>isbar(n+1,0);
    scc_weight.resize(n+1, 0);
    for(int i = 0;i < m;i++) {
        int u, v;
        cin >> u >> v;
        edges[u].push_back(v);
    }
    for(int i = 1;i <= n;i++) cin >> a[i];
    cin >> s >> p;
    for(int i = 1;i <= p;i++) {
        int num;
        cin >> num;
        isbar[num] = 1;
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) tarjan(i);
    }
    vector<vector<int>>dag(scc_cnt+1);
    vector<int>indeg(scc_cnt+1);
    vector<ll>dp(scc_cnt+1);
    int s_sccid = belong[s];
    dp[s_sccid] = scc_weight[s_sccid];
    for(int u = 1;u <= n;u++) {
        for(auto v : edges[u]) {
            if(belong[u] != belong[v]) {
                dag[belong[u]].push_back(belong[v]);
                indeg[belong[v]]++;
            }
        }
    }
    queue<int>q;
    bool flag = false;
    for(int i = 1;i <= scc_cnt;i++) {
        if(indeg[i] == 0) {
            q.push(i);
            if(i == s_sccid) flag = true;
        }
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(u == s_sccid) flag = true;
        for(auto v : dag[u]) {
            if(indeg[v]) {
                if(flag) dp[v] = max(dp[v], dp[u] + scc_weight[v]);
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }
    }
    ll ans = 0;
    for(int i = 1;i <= n;i++) {
        if(isbar[i]) ans = max(ans, dp[belong[i]]);
    }
    cout << ans;
    return 0;
}