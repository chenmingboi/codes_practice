#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
vector<int>dfn, low, belong;
vector<char>instack;

void tarjan(int u, int& tot, int& scc_cnt, stack<int>& st) {
    dfn[u] = low[u] = ++tot;
    st.push(u);
    instack[u] = 1;
    for(auto v : edges[u]) {
        if(!dfn[v]) {
            tarjan(v, tot, scc_cnt, st);
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
        } while(u != v);
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //也就是看x和y是否在同一个强连通图中，额，题目中说是从x到y或者是从y到x都可以
    //也就是说任意两点之间均可达到，但不要求双向互达
    //可以用看各个连通分量之间有没有边相连，然后构建有向无环图之后进行拓扑排序且有且只有有一种排序
    //也就是除了初始的节点入度为0之外其余节点入度均为1，且有向无环图中总结点数要等与连通分量总数
    //防止有一个孤立的连通分量的情况
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        edges.assign(n+1, vector<int>()), dfn.assign(n+1, 0), low.assign(n+1, 0);
        belong.assign(n+1, 0), instack.assign(n+1, 0);
        stack<int>st;
        int tot = 0, scc_cnt = 0;
        for(int i = 0;i < m;i++) {
            int u, v;
            cin >> u >> v;
            edges[u].push_back(v);
        }
        for(int i = 1;i <= n;i++) {
            if(!dfn[i]) tarjan(i, tot, scc_cnt, st);
        }
        vector<vector<int>>dag(scc_cnt+1);
        vector<int>indeg(scc_cnt+1);
        for(int u = 1;u <= n;u++) {
            for(auto v : edges[u]) {
                if(belong[u] != belong[v]) {
                    dag[belong[u]].push_back(belong[v]);
                    indeg[belong[v]]++;
                }
            }
        }
        //拓扑排序
        queue<int>q;
        for(int i = 1;i <= scc_cnt;i++) {
            if(indeg[i] == 0) q.push(i);
        }
        bool flag = true;
        while(!q.empty()) {
            if(q.size() > 1) {
                flag = false;
                break;
            }
            int u = q.front();
            q.pop();
            for(auto v : dag[u]) {
                if(indeg[v]) {
                    indeg[v] -= 1;
                    if(indeg[v] == 0) {
                        q.push(v);
                    }
                }
            }
        }
        if(flag) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
    return 0;
}