#include<bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
int n, ans = 0, maxx = 0, maxy = 0;
vector<int>partner;
vector<bool>use;
vector<pair<int, int>>position;
vector<int>rightWorm(12);//每个虫洞x正方向的最近虫洞编号，-1表示没有

void preprocess() {
    for(int i = 0;i < n;i++) {
        auto [x, y] = position[i];
        int best = -1, bestx = INF;
        for(int j = 0;j < n;j++) {
            auto [x1, y1] = position[j];
            if(y1 == y && x1 < bestx && x1 > x) {
                bestx = min(bestx, x1);
                best = j;
            }
        }
        rightWorm[i] = best;
    }
}
int findChongdongIndex(int x, int y) {
    for(int i = 0;i < n;i++) {
        auto [x1, y1] = position[i];
        if(x == x1 && y == y1) return i;
    }
    return -1;
}

bool check() {
    //从第i个虫洞开始
    for(int i = 0;i < n;i++) {
        vector<bool>vis(n, false);//记录某个虫洞是否被遇到过
        int cur = i;
        while(true) {
            //先往正方向走再跃迁
            int nxt = rightWorm[cur];//往cur的x正方向走
            if(nxt == -1) break;//cur正方向上没有虫洞不会循环
            if(vis[nxt]) return true;
            vis[nxt] = true;
            cur = partner[nxt];
        }
    }
    return false;
}
void dfs(int step) {
    if(step == n/2) {
        if(check()) {
            ans++;
        }
        return;
    }
    //找到第一个还未配对的
    int first = -1;
    for(int i = 0;i < n;i++) {
        if(!use[i]) {
            first = i;
            break;
        }
    }
    use[first] = true;
    for(int i = first+1;i < n;i++) {
        if(!use[i]) {
            use[i] = true;
            partner[first] = i;
            partner[i] = first;
            dfs(step+1);
            use[i] = false;
            partner[first] = partner[i] = -1;
        }
    }
    use[first] = false;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    partner.resize(n, -1);
    use.resize(n, false);
    position.resize(n);
    rightWorm.resize(n, -1);
    for(int i = 0;i < n;i++) {
        int x, y;
        cin >> x >> y;
        position[i] = {x, y};
    }
    preprocess();
    dfs(0);
    cout << ans;
    return 0;
}