#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    deque<int>q, w;
    vector<int>a(n+1, 0);
    for(int i = 1;i <= n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++) {
        //1.清除已经不在滑动窗口内的元素下标
        while(!q.empty() && q.front() < i-k+1) {
            q.pop_front();
        }
        //2.清楚比a[i]小的元素下标
        while(!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        //3.把i加入
        q.push_back(i);
        //4.判断长度是否超过窗口长度
        if(i >= k) {
            cout << a[q.front()] << ' ';
        }
    }
    cout << endl;
    for(int i = 1;i <= n;i++) {
        while(!w.empty() && w.front() < i-k+1) {
            w.pop_front();
        }
        while(!w.empty() && a[w.back()] <= a[i]) {
            w.pop_back();
        }
        w.push_back(i);
        if(i >= k) {
            cout << a[w.front()] << ' ';
        }
    }
    return 0;
}