#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //每个函数最多贡献m个值
    //算出每个函数的最小m个值，然后再添加到数组中进行sort
    //题目中x属于正整数，且a >= 1, b>=0,所以从x=1开始算即可
    int n, m;
    cin >> n >> m;
    vector<vector<int>>canshu(n, vector<int>(3));
    priority_queue<int, vector<int>, greater<int>>ans;
    priority_queue<int, vector<int>, less<int>>maxHeap;
    for(int i = 0;i < n;i++) {
        cin >> canshu[i][0] >> canshu[i][1] >> canshu[i][2];
    }
    for(int i = 0;i < n;i++) {
        for(int j = 1;j <= m;j++) {
            int res = canshu[i][0] * pow(j, 2) + canshu[i][1] * j + canshu[i][2];
            //通过维护maxHeap,来去除一些肯定不在前m个小元素中的值
            if(ans.size() >= m) {
                if(res >= maxHeap.top()) {
                    continue;
                } else {
                    ans.push(res);
                    //maxHeap维持前m个元素中最大的元素
                    maxHeap.push(res);
                    maxHeap.pop();
                }
            } else {
                ans.push(res);
                maxHeap.push(res);
            }
        }
    }
    for(int i = 0;i < m;i++) {
        cout << ans.top() << ' ';
        ans.pop();
    }
    return 0;
}