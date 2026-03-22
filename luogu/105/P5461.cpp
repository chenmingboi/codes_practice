#include<bits/stdc++.h>
using namespace std;

void chuli(vector<vector<int>>&result, int hang, int lie, int len) {
    if(len == 0) return;
    //处理左上的变为0
    for(int i = hang;i < hang+len;i++) {
        for(int j = lie;j < lie+len;j++) {
            result[i][j] = 0;
        }
    }
    //处理右上
    chuli(result, hang, lie+len, len/2);
    //处理左下
    chuli(result, hang+len, lie, len/2);
    //处理右下
    chuli(result, hang+len, lie+len, len/2);
}
int main() {
    int n;
    cin >> n;
    int len = pow(2, n);
    vector<vector<int>>result(len, vector<int>(len, 1));
    chuli(result, 0, 0, len/2);
    for(int i = 0;i < len;i++) {
        for(int j = 0;j < len;j++) {
            cout << result[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}