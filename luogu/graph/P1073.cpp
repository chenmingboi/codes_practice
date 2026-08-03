#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
struct node{
    int l;
    int h;
    node() : l(INF), h(0) {}
};
vector<vector<int>>edges;
vector<int>dfn, low, belong;
vector<char>instack;
stack<int>st;
vector<int>a;
//记录在每个强连通分量中的最小的买入价和最高的卖出价
vector<int>mn;
vector<int>mx;
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
            mn[scc_cnt] = min(mn[scc_cnt], a[v]);
            mx[scc_cnt] = max(mx[scc_cnt], a[v]);
        } while(u != v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1), dfn.resize(n+1), low.resize(n+1);
    belong.resize(n+1), instack.resize(n+1, 0), a.resize(n+1);
    mn.resize(n+1, INF), mx.resize(n+1);
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 0;i < m;i++) {
        int x, y, z;
        cin >> x >> y >> z;
        edges[x].push_back(y);
        if(z == 2) edges[y].push_back(x);
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) tarjan(i);
    }
    vector<vector<int>>dag(scc_cnt+1);
    //反向图，用于反向dp
    vector<vector<int>>rdag(scc_cnt+1);
    vector<int>indeg(scc_cnt+1);
    vector<int>outdeg(scc_cnt+1);
    for(int u = 1;u <= n;u++) {
        for(auto v : edges[u]) {
            if(belong[u] != belong[v]) {
                dag[belong[u]].push_back(belong[v]);
                rdag[belong[v]].push_back(belong[u]);
                indeg[belong[v]]++;
                outdeg[belong[u]]++;
            }
        }
    }
    //正向DP，记录从1开始到达i的路径中的最小买入价
    queue<int>q;
    vector<int>lowest(scc_cnt+1, INF);
    //必须在1号出发
    int s_sccid = belong[1];
    lowest[s_sccid] = mn[s_sccid];
    for(int i = 1;i <= scc_cnt;i++) {
        if(indeg[i] == 0) q.push(i);
    }
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(auto v : dag[u]) {
            if(lowest[u] != INF) {
                lowest[v] = min({lowest[v], lowest[u], mn[v]});
                indeg[v]--;
                if(indeg[v] == 0) q.push(v);
            }
        }
    }
    //反向DP, 知识点
    vector<int>highest(scc_cnt+1, 0);
    queue<int>q2;
    for(int i = 1;i <= scc_cnt;i++) {
        if(outdeg[i] == 0) q2.push(i);
    }
    int n_sccid = belong[n];
    highest[n_sccid] = mx[n_sccid];
    while(!q2.empty()) {
        int u = q2.front();q2.pop();
        for(auto v : rdag[u]) {
            if(highest[u] != 0) {
                highest[v] = max({highest[u], highest[v], mx[v]});
                outdeg[v]--;
                if(outdeg[v] == 0) q2.push(v);
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= scc_cnt;i++) {
        if(lowest[i] != INF && highest[i] != 0) {
            ans = max(ans, highest[i] - lowest[i]);
        }
    }
    //题目中还有一个条件就是必须在n号结束自己的旅行
    //还有一个限制条件，就是在1号出发
    cout << ans;
    return 0;
}