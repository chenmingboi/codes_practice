#include<bits/stdc++.h>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
    //这种排序方法不对，因为如果出现一个开始时间早的但是持续时间长
    //比如0-5会排在1-2前面，但是1-2理应排在0-5前面
    // if(a.first < b.first) {
    //     return a.first < b.first;
    // } else {
    //     return a.second < b.second;
    // }
    return a.second < b.second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>>test(n);
    for(int i = 0;i < n;i++) {
        cin >> test[i].first >> test[i].second;
    }
    sort(test.begin(), test.end(), comp);
    int num = 0, lastend = 0;
    for(int i = 0;i < n;i++) {
        if(test[i].first >= lastend) {
            num++;
            lastend = test[i].second;
        }
    }
    cout << num;
    return 0;
}