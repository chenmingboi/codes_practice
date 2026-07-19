#include<bits/stdc++.h>
using namespace std;

//st_min[i][j]表示的是从i开始区间长度为2^j中元素的最小值
vector<vector<int>>st_min;
vector<vector<int>>st_max;
vector<int>h;

void init(int n) {
    for(int i = 0;i < n;i++) {
        st_min[i][0] = h[i];
        st_max[i][0] = h[i];
    }
    //枚举区间长度， 感觉有点像分治做法中的从底向上
    //需要先算短的区间长度中的st值，后面长区间是依赖段区间的值的
    for(int j = 1;(1 << j) <= n;j++) {
        for(int i = 0;i + (1 << j) <= n;i++) {
            st_min[i][j] = min(st_min[i][j-1], st_min[i+(1 << (j-1))][j-1]);
            st_max[i][j] = max(st_max[i][j-1], st_max[i+(1 << (j-1))][j-1]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    h.resize(n);
    st_min.resize(n, vector<int>(__lg(n) + 1));
    st_max.resize(n, vector<int>(__lg(n) + 1));
    for(int i = 0;i < n;i++) {
        cin >> h[i];
    }
    init(n);
    for(int i = 0;i < q;i++) {
        int a, b, k;
        cin >> a >> b;
        //注意题目中下标是从1开始的
        //使得2^k <= 区间长度 <= 2^(k+1)
        //__lg返回的是向上取整的数值⌊log2​(x)⌋返回int更准确
        k = __lg(b-a+1);
        //这里是b-(1<<k)+1因为要保证区间长度为2^k到b,如果是从b-(1<<k)开始算的话到的是b-1
        int h_min = min(st_min[a-1][k], st_min[b-(1<<k)][k]);
        int h_max = max(st_max[a-1][k], st_max[b-(1<<k)][k]);
        cout << h_max - h_min << '\n';
    }
    return 0;
}