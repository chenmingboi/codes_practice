// #include<bits/stdc++.h>
// using namespace std;

// pair<int, int> find_max(int l, int k, const string& num) {
//     int ans = INT_MIN;
//     int index = 0;
//     for(int i = l;i < l+k && i < num.length();i++) {
//         if(num[i]-'0' > ans) {
//             ans = num[i]-'0';
//             index = i;
//         }
//     }
//     return {ans, index};
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string num;
//     int k;
//     cin >> num;
//     cin >> k;
//     int l = 0;
//     vector<int>result;
//     while(k && l+k < num.length()) {
//         auto [m, index] = find_max(l, k, num);
//         if(num[l+k]-'0' > m) {
//             l = l + k;
//             while(l < num.length()) {
//                 result.push_back(num[l]-'0');
//                 l++;
//             }
//             k = 0;
//         } else {
//             result.push_back(num[index]-'0');
//             k -= (index - l);
//             l = index+1;
//         }
//     }
//     for(int i = l+k;i < num.length();i++) {
//         result.push_back(num[i]-'0');
//     }
//     reverse(result.begin(), result.end());
//     while(result.back() == 0 && result.size() > 1) result.pop_back();
//     reverse(result.begin(), result.end());
//     for(auto it : result) cout << it;
//     return 0;
// }

//单调栈

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string num;
    int k;
    cin >> num;
    cin >> k;
    string ans;
    for(char c : num) {
        while(!ans.empty() && k > 0 && ans.back() < c) {
            k--;
            ans.pop_back();
        }
        ans.push_back(c);
    }
    //此时ans是降序排列的,如果还没有删够,从末尾开始删除
    while(k) {
        ans.pop_back();k--;
    }
    reverse(ans.begin(), ans.end());
    while(ans.size() > 1 && ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    cout << ans;
    return 0;
}