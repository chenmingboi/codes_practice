#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges, belong;
vector<int>dfn, low;
vector<char>instack;
stack<int>st;
int tot = 0, scc_cnt = 0;
int ans_id, maxsize = 0;
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
            belong[scc_cnt].emplace_back(v);
        } while(u != v);
        if(belong[scc_cnt].size() > maxsize) {
            maxsize = belong[scc_cnt].size();
            ans_id = scc_cnt;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //将无向边拆成两条有向边即可，不会影响tarjan算法的运行
    int n, m;
    cin >> n >> m;
    edges.resize(n+1), belong.resize(n+1);
    dfn.resize(n+1), low.resize(n+1);
    instack.resize(n+1, 0);
    for(int i = 0;i < m;i++) {
        int a, b, t;
        cin >> a >> b >> t;
        edges[a].emplace_back(b);
        if(t == 2) edges[b].emplace_back(a);
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) tarjan(i);
    }
    sort(belong[ans_id].begin(), belong[ans_id].end());
    cout << maxsize << '\n';
    for(auto node : belong[ans_id]) cout << node << ' ';
    return 0;
}