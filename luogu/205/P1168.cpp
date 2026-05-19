#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //其实就是第k小元素(k为中位)
    //利用大顶堆和小顶堆实现对数列的二分
    //添加元素的时候要保证minHeap.size和maxHeap.size相差值不大于一
    //且因为是求前奇数项，所以这里选择maxHeap总比minHeap多一个元素
    //此时maxHeap.top即为前奇数项的中位数
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0;i < n;i++) {
        cin >> a[i];
    }
    priority_queue<int, vector<int>, greater<int>>minHeap;
    priority_queue<int, vector<int>, less<int>>maxHeap;
    //第一个中位数为a[0]
    maxHeap.push(a[0]);
    cout << a[0] << endl;
    for(int i = 1;i < (n+1)/2;i++) {
        //每次i++,都要向minHeap和maxHeap中总共添加两个元素
        //添加的两个元素的下标为2i-1和2i
        for(int j = 2*i-1;j <= 2*i;j++) {
            if(a[j] >= maxHeap.top()) {
                minHeap.push(a[j]);
            } else {
                maxHeap.push(a[j]);
            }
        }
        //调整两个Heap中的元素数量
        while(maxHeap.size() - minHeap.size() != 1) {
            //maxHeap中的元素比minHeap多了超过一个
            if(maxHeap.size() > minHeap.size()) {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
            } else {
                maxHeap.push(minHeap.top());
                minHeap.pop();
            }
        }
        cout << maxHeap.top() << endl;
    }
    return 0;
}