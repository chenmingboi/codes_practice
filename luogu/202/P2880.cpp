#include<bits/stdc++.h>
using namespace std;

int n;
vector<int>lg;
//st[i][j]表示从下标i开始的长度为2^j的区间中的最大值or最小值
vector<vector<int>>st_max;
vector<vector<int>>st_min;
vector<int>h;

void init(int n) {
    for(int i = 1;i <= n;i++) {
        st_max[i][0] = h[i];
        st_min[i][0] = h[i];
    }
    //枚举区间长度2^j
    for(int j = 1;(1 << j) <= n;j++) {
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            //把整个2^j长度的区间分成两份，每份的长度为2^(j-1)
            st_max[i][j] = max(st_max[i][j-1], 
                        st_max[i+(1<<(j-1))][j-1]);
        }
    }
    for(int j = 1;(1 << j) <= n;j++) {
        for(int i = 1;i + (1 << j) - 1 <= n;i++) {
            st_min[i][j] = min(st_min[i][j-1],
                        st_min[i + (1 << (j-1))][j-1]);
        }
    }
}

void ask(int l, int r) {
    int k = lg[r-l+1];//找到k使得2^k <= 区间长度 <= 2^(k+1)
    //一个从左端点开始，一个以右端点结束
    int h_max = max(st_max[l][k], st_max[r-(1<<k)+1][k]);
    int h_min = min(st_min[l][k], st_min[r-(1<<k)+1][k]);
    cout << h_max - h_min << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> n >> q;
    lg.resize(n+1);
    lg[1] = 0;//lg 以2为底数的对数
    for(int i = 2;i <= n;i++) {
        lg[i] = lg[i/2] + 1;
    }
    int k = lg[n]+1;
    //注意这里st表的第二维不需要开n+1,因为第二维使用来表示区间长度的
    //2^k >= n即可，所以可以用k=lg[n] + 1
    st_max.resize(n+1, vector<int>(k)), 
    st_min.resize(n+1, vector<int>(k)), h.resize(n+1);
    for(int i = 1;i <= n;i++) {
        cin >> h[i];
    }
    init(n);
    for(int i = 0;i < q;i++) {
        int a, b;
        cin >> a >> b;
        ask(a, b);
    }
    return 0;
}