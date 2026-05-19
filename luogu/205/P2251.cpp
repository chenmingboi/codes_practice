#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>q(n);
    for(int i = 0;i < n;i++) {
        cin >> q[i];
    }
    //滑动窗口
    //维护一个单调队列
    deque<pair<int, int>>d;
    for(int i = 0;i < n;i++) {
        //处理新添加的元素
        while(!d.empty() && q[i] <= d.back().first) {
            //后来的小值总比先到大值的停留时间更长
            d.pop_back();
        }
        d.push_back({q[i], i});
        if(i >= m-1) {
            //第一个窗口已经完成，之后每次添加元素都要判断是否要pop掉front
            int frontIndex = d.front().second;
            if(frontIndex >= i+1-m) {
                //还在窗口内
                cout << d.front().first << endl;
            } else {
                //不在窗口内了,由于每次仅添加一个元素，所以只需要pop掉一个就行
                d.pop_front();
                cout << d.front().first << endl;
            }
        }
    }
    return 0;
}