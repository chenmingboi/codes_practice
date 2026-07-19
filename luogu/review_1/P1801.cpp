#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<int>a(m+1), u(n);
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 0;i < n;i++) cin >> u[i];
    priority_queue<int, vector<int>, greater<int>>minHeap;
    priority_queue<int, vector<int>, less<int>>maxHeap;
    //大顶堆 -> <- 小顶堆
    int last = 1;
    for(int i = 0;i < n;i++) {
        for(int j = last;j <= u[i];j++) {
            if(maxHeap.size() != 0) {
                if(a[j] < maxHeap.top()) {
                    maxHeap.push(a[j]);
                } else {
                    minHeap.push(a[j]);
                }
            } else {
                minHeap.push(a[j]);
            }
        }
        last = u[i]+1;
        while(maxHeap.size() < i+1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        while(maxHeap.size() > i+1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        cout << maxHeap.top() << '\n';
    }
    return 0;
}