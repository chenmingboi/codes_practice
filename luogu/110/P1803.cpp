#include<bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    //结束时间尽可能早，不影响后面的比赛
    // （开始时间尽可能晚，不影响前面的比赛）没必要，因为
    //如果结束时间相同的时候，开始时间早晚只能选择一个
    //考虑如果有两个比赛，a, b a的结束时间和b的结束时间相同，且a的开始时间早于b
    //此时选择a/b都可以，因为假设有一个c结束时间在b的开始时间之前，由于先选结束时间早的
    //所以此时会选c和b，而不是a,是正确的
    return a.second < b.second;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>>time(n);
    for(int i = 0;i < n;i++) {
        cin >> time[i].first >> time[i].second;
    }
    sort(time.begin(), time.end(), cmp);
    int lastend_time = 0, ans = 0;
    for(int i = 0;i < n;i++) {
        if(time[i].first >= lastend_time) {
            ans++;
            lastend_time = time[i].second;
        }
    }
    cout << ans;
    return 0;
}