#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string>words(n);
    for(int i = 0;i < n;i++) {
        cin >> words[i];
    }
    string danci = "yizhong";
    int len = danci.length();
    vector<int>x {-1, -1, -1, 0, 0, 1, 1, 1};
    vector<int>y {-1, 0, 1, -1, 1, -1, 0, 1};
    vector<vector<bool>> vis(n, vector<bool>(n, false));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(words[i][j] != 'y') continue;
            for(int d = 0;d < 8;d++) {
                //八个方向
                bool ok = true;
                int dx = x[d], dy = y[d];
                vector<pair<int, int>>path;
                for(int l = 0;l < len;l++) {
                    int nx = i + dx * l;
                    int ny = j + dy * l;
                    if(nx < 0 || nx >= n || ny < 0 || ny >= n) {
                        //判断是否越界
                        ok = false; break;
                    }
                    //不能和不相等一起判断，因为越界的时候此时不能访问words
                    if(words[nx][ny] != danci[l]) {
                        ok = false;
                        break;
                    }
                    path.push_back({nx, ny});
                }
                if(ok) {
                    for(auto &it : path) {
                        vis[it.first][it.second] = true;
                    }
                }
            }
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            if(vis[i][j]){
                cout << words[i][j];
            } else {
                cout << '*';
            }
        }
        cout << endl;
    }
    return 0;
}