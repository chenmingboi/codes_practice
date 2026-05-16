#include<bits/stdc++.h>
using namespace std;

int x, y, mx, my;
vector<vector<bool>>isMorStone;
vector<int>dhang = {1, 1, 1, 0, 0, -1, -1, -1};
vector<int>dlie = {-1, 0, 1, -1, 1, -1, 0, 1};

int bfs(const vector<vector<char>>&muchang) {
    queue<pair<int, int>>q;
    q.push({my, mx});
    int pushNum = 1, ans = 0;
    while(!q.empty()) {
        int tempNum = 0;
        //添加每一周中新感染的牧草
        while(pushNum) {
            int hang, lie;
            auto front = q.front();
            hang = front.first, lie = front.second;
            for(int i = 0;i < 8;i++) {
                int newHang = hang+dhang[i], newLie = lie+dlie[i];
                if(!isMorStone[newHang][newLie]
                    && newHang >= 1 && newHang <= y
                    && newLie >= 1 && newLie <= x) {
                    q.push({newHang, newLie});
                    //标记为M
                    isMorStone[newHang][newLie] = true;
                    //这一周中感染的牧草数量
                    tempNum++;
                }
            }
            q.pop();
            pushNum--;
        }
        //该周结束，如果没有感染牧草则说明已经全部感染，此时q中为empty
        //如果还有感染的则ans++;
        if(tempNum) {
            pushNum = tempNum;
            ans++;
        }
    }
    return ans;
}
//利用bfs队列
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> x >> y >> mx >> my;
    vector<vector<char>>muchang(y+2, vector<char>(x+2));
    isMorStone.resize(y+2, vector<bool>(x+2, false));
    isMorStone[my][mx] = true;
    for(int i = 1;i <= y;i++){
        for(int j = 1;j <= x;j++) {
            cin >> muchang[y-i+1][j];
            if(muchang[y-i+1][j] == '*') {
                isMorStone[y-i+1][j] = true;
            }
        }
    }
    cout << bfs(muchang);
    return 0;
}