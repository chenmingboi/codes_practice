#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>>world(n+1,vector<int>(n+1, 0));
    for(int i = 0;i < m;i++){
        int x, y;
        cin >> x >> y;
        for(int j = (x - 2) >= 0 ? (x - 2) : 0;j <= x+2 && j <= n;j++){
            world[y][j] = 1;
        }
        for(int j = (y - 2) >= 0 ? (y - 2) : 0;j <= y+2 && j <= n;j++){
            world[j][x] = 1;
        }
        if(y+1 <= n && x+1 <= n) {
            world[y+1][x+1] = 1;
        }
        if(y-1>=0  && x+1 <= n) {
            world[y-1][x+1] = 1;
        }
        if(y+1 <= n && x-1 >= 0) {
            world[y+1][x-1] = 1;
        }
        if(y-1 >= 0 && x-1 >= 0){
            world[y-1][x-1] = 1;
        }
    }
    for(int i = 0;i < k;i++){
        int x, y;
        cin >> x >> y;
        for(int j = (y-2) >= 0 ? (y-2) : 0;j <= y+2 && j <= n;j++){
            for(int k = (x-2) >= 0 ? (x-2) : 0;k <= x+2 && k <= n;k++){
                world[j][k] = 1;
            }
        }
    }
    int ans = 0;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(world[i][j] == 0) ans++;
        }
    }
    cout << ans;
    return 0;
}