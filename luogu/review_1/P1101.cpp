#include<bits/stdc++.h>
using namespace std;

string s = "yizhong";
vector<vector<char>>input, output;
int n;

bool judge(int x, int y, int dir) {
    //dir
    //1:向下 2:左下 3：向左 4：左上 5：向上 6：右上 7：向右 8：右下
    bool flag = true;
    if(dir == 1) {
        for(int i = 0;i <= 6;i++) {
            if(input[x+i][y] != s[i] || x + 6 >= n) {
                flag = false;
                break;
            }
        }
    } else if(dir == 2) {
        for(int i = 0;i <= 6;i++) {
            if(input[x+i][y-i] != s[i] || x+6 >= n || y-6 < 0){
                flag = false;
                break;
            }
        }
    } else if(dir == 3) {
        for(int i = 0;i <= 6;i++) {
            if(input[x][y-i] != s[i] || y-6 < 0) {
                flag = false;
                break;
            }
        }
    } else if(dir == 4) {
        for(int i = 0;i <= 6;i++) {
            if(input[x-i][y-i] != s[i] || x-6 < 0 || y-6 < 0) {
                flag = false;
                break;
            }
        }
    } else if(dir == 5) {
        for(int i = 0;i <= 6;i++) {
            if(input[x-i][y] != s[i] || x-6 < 0) {
                flag = false;
                break;
            }
        }
    } else if(dir == 6) {
        for(int i = 0;i <= 6;i++) {
            if(input[x-i][y+i] != s[i] || x-6 < 0 || y+6 >= n) {
                flag = false;
                break;
            }
        }
    } else if(dir == 7) {
        for(int i = 0;i <= 6;i++) {
            if(input[x][y+i] != s[i] || y+6 >= n) {
                flag = false;
                break;
            }
        }
    } else if(dir == 8) {
        for(int i = 0;i <= 6;i++) {
            if(input[x+i][y+i] != s[i] || x+6 >= n || y+6 >= n) {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    input.resize(n, vector<char>(n)), output.resize(n, vector<char>(n, '*'));
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cin >> input[i][j];
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            int x = i, y = j;
            for(int dir = 1;dir <= 8;dir++) {
                if(judge(x, y, dir)) {
                    if(dir == 1) {
                        for(int k = 0;k <= 6;k++) {
                            output[x+k][y] = s[k];
                        }
                    } else if(dir == 2) {
                        for(int k = 0;k <= 6;k++) {
                            output[x+k][y-k] = s[k];
                        }
                    } else if(dir == 3) {
                        for(int k = 0;k <= 6;k++) {
                            output[x][y-k] = s[k];
                        }
                    } else if(dir == 4) {
                        for(int k = 0;k <= 6;k++) {
                            output[x-k][y-k] = s[k];
                        }
                    } else if(dir == 5) {
                        for(int k = 0;k <= 6;k++) {
                            output[x-k][y] = s[k];
                        }
                    } else if(dir == 6) {
                        for(int k = 0;k <= 6;k++) {
                            output[x-k][y+k] = s[k];
                        }
                    } else if(dir == 7) {
                        for(int k = 0;k <= 6;k++) {
                            output[x][y+k] = s[k];
                        }
                    } else if(dir == 8) {
                        for(int k = 0;k <= 6;k++) {
                            output[x+k][y+k] = s[k];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < n;i++) {
        for(int j = 0;j < n;j++) {
            cout << output[i][j];
        }
        cout << '\n';
    }
    return 0;
}