#include<bits/stdc++.h>
using namespace std;

struct ship {
    int t;
    int k;
    vector<int>x;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<ship>ships(n);
    for(int i = 0;i < n;i++) {
        int t, k;
        cin >> t >> k;
        ships[i].t = t, ships[i].k = k;
        auto& x1 = ships[i].x;
        for(int j = 0;j < k;j++) {
            int inputx;
            cin >> inputx;
            x1.push_back(inputx);
        }
    }
    int l = 0;
    int ans = 0;
    //使用双指针，维护一个时间最小的l，遍历当前船只序列，
    //针对当前船只中的人的国籍，如果cnt[it]==0表示之前没有该国籍的人，ans++
    //然后判断l是否对于r正确，如果时间过长，则l向右移，移动过程中
    //针对舍弃的船只中的人的国籍令cnt[it]--,如果等于0，则表示没有该国籍的人了ans--
    unordered_map<int, int>cnt;
    for(int r = 0;r < n;r++) {
        for(auto& it : ships[r].x) {
            if(cnt[it] == 0) ans++;
            cnt[it]++;
        }
        while(ships[r].t - ships[l].t >= 86400) {
            for(auto& it : ships[l].x) {
                cnt[it]--;
                if(cnt[it] == 0) ans--;
            }
            l++;
        }
        cout << ans << endl;
    }
    //TLE，重复搜索复杂度太高
    // for(int i = 0;i < n;i++) {
    //     int t1 = ships[i].t;
    //     vector<int>totalnum;
    //     for(int j = i;j >= 0;j--) {
    //         int t2 = ships[j].t;
    //         if(t1 - t2 >= 0 && t1 - t2 < 86400) {
    //             for(auto& it : ships[j].x) {
    //                 if(find(totalnum.begin(), totalnum.end(), it) == totalnum.end()) {
    //                     totalnum.push_back(it);
    //                 }
    //             }
    //         } else {
    //             break;
    //         }
    //     }
    //     cout << totalnum.size() << endl;
    // }
    return 0;
}