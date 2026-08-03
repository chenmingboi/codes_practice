#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>edges;
//dfn:记录每个点的时间戳，
//low:能不经过父亲到达的最早遍历的点，可以经过返祖边
//eg: u->v->g然后g有一条边指向u,此时low[g] = min(low[g], dfn[u]);
vector<int>dfn, low;
//flag:标记是否是割点防止重复计数
vector<char>flag;
//tot时间戳，cnt:割点数量
int tot = 0, cnt = 0;

//version1
// void tarjan(int u, int fa) {
//     dfn[u] = low[u] = ++tot;
//     int child = 0;//该节点的子节点数量
//     for(const auto& v : edges[u]) {
//         if(!dfn[v]) {
//             child++;//子节点数量递增
//             tarjan(v, u);//递归遍历子节点
//             //此时子节点已经遍历完成了，low[v]已经更新为final值
//             //所以利用low[v]来对low[u]进行更新
//             low[u] = min(low[u], low[v]);
//             if(fa != u && low[v] >= dfn[u] && !flag[u]) {
//                 //如果不是根节点，且v的子树中的节点最多爬到u，而回不到更早的节点
//                 //此时删除u之后，也将会删除v中节点所有和u相连的边
//                 //此时以v为节点的子树就无法回到原来的连通图中即生成了一个新的联通分量
//                 //这里是大于等于，不能为严格大于，因为可以回到u的情况也是可以的
//                 //因为删除u之后就删除了与u相连的所有边，此时v的子树反正也回不到更早的节点
//                 flag[u] = true;
//                 cnt++;
//             }
//         } else if(v != fa) {
//             //如果已经遍历且不是父节点，那只能是更早的祖先节点或者是其他树上的节点
//             //此时low[v]可能还没有更新所以用dfn[v]进行更新符合数组的定义
//             low[u] = min(low[u], dfn[v]);
//         }
//     }
//     //另加判断该节点是否是根节点，如果是根节点的话需要至少有两个根节点才行
//     //只有一个子节点的话删除该根节点并不会增加连通图的数量
//     if(fa == u && child >= 2 && !flag[u]) {
//         flag[u] = true;
//         cnt++;
//     }
// }

//verson2
void tarjan(int u, int fa) {
    dfn[u] = low[u] = ++tot;
    int child = 0;//该节点的子节点数量
    for(const auto& v : edges[u]) {
        if(!dfn[v]) {
            child++;//子节点数量递增
            tarjan(v, u);//递归遍历子节点
            //此时子节点已经遍历完成了，low[v]已经更新为final值
            //所以利用low[v]来对low[u]进行更新
            low[u] = min(low[u], low[v]);
            //优化版本，只要low[v]>=dfn[u]这个点就有可能是割点
            //!flag[u]只是为了防止重复计算
            if(low[v] >= dfn[u] && !flag[u]) {
                //情况一：u不是根节点的话只要求low[v] >= dfn[u]
                //情况二：u是根节点，要求child > 1
                if(u != fa || child > 1) flag[u] = true, cnt++;
            }
        } else if(v != fa) {
            //如果已经遍历且不是父节点，那只能是更早的祖先节点或者是其他树上的节点
            //此时low[v]可能还没有更新所以用dfn[v]进行更新符合数组的定义
            low[u] = min(low[u], dfn[v]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    edges.resize(n+1), dfn.resize(n+1), low.resize(n+1);
    flag.resize(n+1, 0);
    for(int i = 0;i < m;i++) {
        int x, y;
        cin >> x >> y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for(int i = 1;i <= n;i++) {
        if(!dfn[i]) {
            //一个新的连通分量中起始遍历的点的父亲设置为自己
            tarjan(i, i);
        }
    }
    cout << cnt << '\n';
    for(int i = 1;i <= n;i++) {
        if(flag[i]) cout << i << ' ';
    }
    return 0;
}