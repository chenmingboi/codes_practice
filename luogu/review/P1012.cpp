#include<bits/stdc++.h>
using namespace std;

bool comp(const string& a, const string& b) {
    return a + b > b + a;
}   
//这个不对
//考虑comp("12", "121")，正确结果应该是12121即12排在121前面
//但是下面的排序方法会把121排在12前面
// bool comp(const string& a, const string& b) {
//     int len1 = a.length(), len2 = b.length();
//     int len = min(len1, len2);
//     for(int i = 0;i < len;i++) {
//         if(a[i] != b[i]) {
//             return a[i] > b[i];
//         } else {
//             continue;
//         }
//     }
//     return len1 > len2;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string>input(n);
    for(int i = 0;i < n;i++) cin >> input[i];
    sort(input.begin(), input.end(), comp);
    for(int i = 0;i < n;i++) {
        cout << input[i];
    }
    return 0;
}