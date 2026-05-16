#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    //c++中提供了prioity queue这种抽象的数据结构实现了堆
    //初始化小顶堆
    priority_queue<int, vector<int>, greater<int>> minHeap;
    // //初始化大顶堆
    // priority_queue<int, vector<int>, less<int>> maxHeap;
    // //默认为大顶堆
    // priority_queue<int>heap;
    for(int i = 0;i < n;i++) {
        int op;
        cin >> op;
        if(op == 1) {
            int x;
            cin >> x;
            minHeap.push(x);
        } else if(op == 2) {
            cout << minHeap.top() << endl;
        } else if(op == 3) {
            minHeap.pop();
        }
    }
    return 0;
}
// //实现模板
// int getParentIndex(int index) {
//     if(index == 0) return 0;
//     return (index-1)/2;
// }

// int getLeftChildIndex(int parentIndex, int heapSize) {
//     int ans = 2*parentIndex + 1;
//     if(ans >= heapSize) return -1;//表示没有左子节点
//     return ans;
// }

// int getRightChildIndex(int parentIndex, int heapSize) {
//     int ans = 2 * parentIndex + 2;
//     if(ans >= heapSize) return -1;//表示没有右子节点
//     return ans;
// }

// //维持一个小顶堆，父节点的值小于子节点
// void push(int val, vector<int>& heap) {
//     heap.push_back(val);
//     int size = heap.size();
//     int index = size - 1;
//     while(true) {
//         int parentIndex = getParentIndex(index);
//         //如果满足parent_val <= val那么结束
//         if(heap[parentIndex] <= heap[index]) break;
//         //如果parent_val > val，那么交换parent_val和val
//         swap(heap[parentIndex], heap[index]);
//         //更新index, 继续向上进行比较
//         index = parentIndex;
//     }
// }

// //将堆顶最小元素pop掉
// void pop(vector<int>& heap) {
//     int size = heap.size();
//     //先将对顶元素和堆尾元素进行交换
//     swap(heap[0], heap[size-1]);
//     //然后将交换到堆尾的元素pop掉
//     heap.pop_back();
//     size -= 1;
//     //将交换到堆顶的元素进行和子节点比较并交换
//     int index = 0;
//     while(true) {
//         int leftChildIndex = getLeftChildIndex(index, size);
//         int rightChildIndex = getRightChildIndex(index, size);
//         int parentIndex = index;
//         //取左右子节点中的较小着
//         if(leftChildIndex != -1 && heap[leftChildIndex] < heap[index]) {
//             index = leftChildIndex;
//         } 
//         if(rightChildIndex != -1 && heap[rightChildIndex] < heap[index]) {
//             index = rightChildIndex;
//         }
//         if(index == parentIndex) {
//             break;
//         }
//         swap(heap[parentIndex], heap[index]);
//     }
// }

// void peek(const vector<int>& heap) {
//     //题中默认不会在heap.size()为0的时候进行读取
//     cout << heap[0] << endl;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     vector<int>heap;
//     int n;
//     cin >> n;
//     for(int i = 0;i < n;i++) {
//         int op;
//         cin >> op;
//         if(op == 1) {
//             int x;
//             cin >> x;
//             push(x, heap);
//         } else if(op == 2) {
//             peek(heap);
//         } else if(op == 3) {
//             pop(heap);
//         }
//     }
//     return 0;
// }