// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     //set使用红黑树自动按照升序进行排序,插入的复杂度为O(logn)
//     set<int>num;
//     for(int i = 0;i < n;i++) {
//         int x = 0;
//         cin >> x;
//         num.insert(x);
//     }
//     cout << num.size() << endl;
//     for(auto it : num) {
//         cout << it << ' ';
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int>num(n);
    for(int i = 0;i < n;i++) {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    //去重
    num.erase(unique(num.begin(), num.end()), num.end());
    cout << num.size() << endl;
    for(auto it : num) {
        cout << it << ' ';
    }
    return 0;
}