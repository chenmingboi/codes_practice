#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    priority_queue<int, vector<int>, greater<int>>minHeap;
    for(int i = 0;i < n;i++) {
        int a;
        cin >> a;
        minHeap.push(a);
    }
    if(minHeap.size() == 1) {
        cout << 0;
        return 0;
    }
    while(minHeap.size() != 1) {
        int first = minHeap.top();
        minHeap.pop();
        int second = minHeap.top();
        minHeap.pop();
        int newWeight = first + second;
        ans += newWeight;
        minHeap.push(newWeight);
        //这里不应该是push ans而是应该push first + second
        // minHeap.push(ans);
    }
    cout << ans;
    return 0;
}