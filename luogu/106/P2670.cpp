#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>>map(n+2, vector<char>(m+2));
    vector<vector<char>>result(n+2, vector<char>(m+2));
    for(int i = 0;i < n+2;i++) {
        //通过在输入的map四周添加一圈.来优化下面数地雷数量的时候的边界判断
        for(int j = 0;j < m+2;j++) {
            if(i == 0 || i == n+1 || j == 0 || j == m+1) {
                map[i][j] = '.';
            } else {
                cin >> map[i][j];
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            if(map[i][j] == '*') {
                result[i][j] = '*';
            } else {
                int num = 0;
                if(map[i-1][j-1] == '*') num++;
                if(map[i-1][j] == '*') num++;
                if(map[i-1][j+1] == '*') num++;
                if(map[i][j-1] == '*') num++;
                if(map[i][j+1] == '*') num++;
                if(map[i+1][j-1] == '*') num++;
                if(map[i+1][j] == '*') num++;
                if(map[i+1][j+1] == '*') num++;
                result[i][j] = char(num+'0');
            }
        }
    }
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= m;j++) {
            cout << result[i][j];
        }
        cout << endl;
    }
    return 0;
}