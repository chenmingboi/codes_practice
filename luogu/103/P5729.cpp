#include<bits/stdc++.h>
using namespace std;

int main(){
    int w, e, h;
    cin >> w >> e >> h;
    vector<vector<vector<int>>>sqare(w+1,vector<vector<int>>(e+1, vector<int>(h+1, 1)));
    int q;
    cin >> q;
    for(int i = 0;i < q;i++){
        int x1, y1, z1, x2, y2, z2;
        cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
        for(int x = x1; x <= x2;x++){
            for(int y = y1; y <= y2;y++){
                for(int z = z1; z <= z2;z++){
                    sqare[x][y][z] = 0;
                }
            }
        }
    }
    int ans = 0;
    for(int x = 1;x <= w;x++){
        for(int y = 1;y <= e;y++){
            for(int z = 1;z <= h;z++){
                if(sqare[x][y][z] == 1) ans++;
            }
        }
    }
    cout << ans;
    return 0;
}