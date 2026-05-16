#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<int>a(m);
    //小顶堆中用来存储除了前i个最小元素之外的剩余元素
    priority_queue<int, vector<int>, greater<int>> minHeap;
    //大顶堆中用来存储前i个小元素，堆顶即为第i小元素
    priority_queue<int, vector<int>, less<int>> maxHeap;
    for(int i = 0;i < m;i++) {
        cin >> a[i];
    }
    int lastu = 0;
    for(int i = 1;i <= n;i++) {
        int u;
        cin >> u;
        //添加元素
        if(u > lastu) {
            //针对添加的每一个元素进行判断，因为要维持maxHeap中的元素都要小于minHeap中的元素
            //当插入元素大于等于maxHeap.top()的时候插入minHeap，否则插入maxHeap
            for(int j = lastu;j < u;j++) {
                if(!maxHeap.empty() && a[j] >= maxHeap.top()) {
                    minHeap.push(a[j]);
                } else {
                    maxHeap.push(a[j]);
                }
            }
            lastu = u;
        }
        //添加完之后对maxheap和minHeap大小进行调整，因为要的是第i小的，所以maxHeap的大小需要等于i
        //如果maxHeap的大小大于i
        while(maxHeap.size() > i) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        //如果maxHeap的大小小于i
        while(maxHeap.size() < i) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        //maxHeap的size = i
        cout << maxHeap.top() << endl;
    }
    return 0;
}