#include<bits/stdc++.h>
using namespace std;

//TLE
int result = 0;
int xb, yb, xm, ym;
// bool judge(int x, int y) {
//     if((x == xm-2 && y == ym-1) || (x == xm-2 && y == ym+1) ||
//         (x == xm-1 && y == ym-2) || (x == xm-1 && y == ym+2) || 
//         (x == xm+1 && y == ym-2) || (x == xm+1 && y == ym+2) ||
//         (x == xm+2 && y == ym-1) || (x == xm+2 && y == ym+1) ||
//         (x == xm && y == ym)) {
//             return true;
//     }
//     return false;
// }
// void move(int x, int y) {
//     if(judge(x, y)) {
//         return;
//     }
//     if(x > xb || y > yb) {
//         return;
//     } 
//     if(x == xb && y == yb) {
//         result++;
//         return;
//     }
//     //向下
//     move(x+1, y);
//     //向右
//     move(x, y+1);
// }

// void change(int x, int y, vector<vector<long long>>&f) {
//     if((x == xm-2 && y == ym-1) || (x == xm-2 && y == ym+1) ||
//         (x == xm-1 && y == ym-2) || (x == xm-1 && y == ym+2) || 
//         (x == xm+1 && y == ym-2) || (x == xm+1 && y == ym+2) ||
//         (x == xm+2 && y == ym-1) || (x == xm+2 && y == ym+1) ||
//         (x == xm && y == ym)) {
//             f[x][y] = 0;
//     }
//     return;
// }
int dx[9] = {0, -2, -2, -1, -1, 1, 1, 2, 2};
int dy[9] = {0, -1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> xb >> yb >> xm >> ym;
    // move(0, 0);
    vector<vector<long long>>f(21, vector<long long>(21,0));
    vector<vector<bool>>ban(21, vector<bool>(21,false));
    //先ban再dp
    //如果按照之前的写法把第一行和第一列全部赋值为1,这样会导致错误，因为在被
    //ban的点的右方是不能到达的，如果在dp的过程中再ban只会更新被ban的点，这样第一列被ban的点
    //的右方仍然为错误值1，不会被更新为0这样就会导致错误
    for(int i = 0;i < 9;i++) {
        int x = xm + dx[i];
        int y = ym + dy[i];
        if(x >= 0 && x <= xb && y >= 0 && y <= yb) {
            ban[x][y] = true;
        }
    }
    if(ban[0][0]) {
        cout << 0;
        return 0;
    }
    f[0][0] = 1;
    for(int i = 0;i <= xb;i++) {
        for(int j = 0;j <= yb;j++) {
            if(ban[i][j]) {
                f[i][j] = 0;
                continue;
            }
            if(i >= 1) f[i][j] += f[i-1][j];
            if(j >= 1) f[i][j] += f[i][j-1];
        }
    }
    cout << f[xb][yb];
    return 0;
}

//emmm 如果要想到达一个点，则必然上一步是在其上方或者左方 
//可以用二维数组存储到达某个点的路线条数
//也就是f[i][j] = f[i-1][j] + f[i][j-1];

