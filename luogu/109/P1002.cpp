#include<bits/stdc++.h>
using namespace std;

//TLE
int result = 0;
int xb, yb, xm, ym;
bool judge(int x, int y) {
    if((x == xm-2 && y == ym-1) || (x == xm-2 && y == ym+1) ||
        (x == xm-1 && y == ym-2) || (x == xm-1 && y == ym+2) || 
        (x == xm+1 && y == ym-2) || (x == xm+1 && y == ym+2) ||
        (x == xm+2 && y == ym-1) || (x == xm+2 && y == ym+1) ||
        (x == xm && y == ym)) {
            return true;
    }
    return false;
}
void move(int x, int y) {
    if(judge(x, y)) {
        return;
    }
    if(x > xb || y > yb) {
        return;
    } 
    if(x == xb && y == yb) {
        result++;
        return;
    }
    //向下
    move(x+1, y);
    //向右
    move(x, y+1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> xb >> yb >> xm >> ym;
    // move(0, 0);
    vector<vector<int>>f(21, vector<int>(21,0));
    f[0][1] = 1;
    f[1][0] = 1;
    for(int i = 0;i)
    cout << result;
    return 0;
}

//emmm 如果要想到达一个点，则必然上一步是在其上方或者左方 
//可以用二维数组存储到达某个点的路线条数
//也就是f[i][j] = f[i-1][j] + f[i][j-1];

