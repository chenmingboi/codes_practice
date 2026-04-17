#include<bits/stdc++.h>
using namespace std;


// //返回-1表示都比mark小，返回比mark大的分数中最小的分数的下标
// int findMinLa(const vector<int>& a, const int& l, const int& r, const int& mark) {
//     int mid = l + (r - l) / 2;
//     if(l > r) {
//         return -1;
//     }
//     if(a[mid] < mark) {
//         return findMinLa(a, mid+1, r, mark);
//     } else if(a[mid] > mark) {
//         if(mid >= 1) {
//             if(a[mid-1] < mark) {
//                 return mid;
//             } else {
//                 return findMinLa(a, l, mid-1, mark);
//             }
//         } else {
//             return mid;
//         }
//     } else if(a[mid] == mark) {
//         return mid;
//     }
// }

// //return -1表示都比mark大，找比分数低中的最高的分数的下标
// int findMaxSm(const vector<int>& a, const int& l, const int& r, const int& mark) {
//     int mid = l + (r - l) / 2;
//     if(l > r) {
//         return -1;
//     }
//     if(a[mid] < mark) {
//         if(mid + 1 <= a.size()-1) {
//             if(a[mid+1] <= mark) {
//                 return findMaxSm(a, mid+1, r, mark);
//             } else {
//                 return mid;
//             }
//         } else {
//             return mid;
//         }
//     } else if(a[mid] > mark) {
//         return findMaxSm(a, l, mid-1, mark);
//     } else if(a[mid] == mark) {
//         return mid;
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     //使用二分查找学校的分数，预计复杂度为nlogm
//     int m, n;
//     cin >> m >> n;
//     vector<int>a(m), b(n);
//     for(int i = 0;i < m;i++) {
//         cin >> a[i];
//     }
//     for(int i = 0;i < n;i++) {
//         cin >> b[i];
//     }
//     sort(a.begin(), a.end());
//     long long result = 0;
//     for(int i = 0;i < n;i++) {
//         int sm_index = findMaxSm(a, 0, m-1, b[i]);
//         int la_index = findMinLa(a, 0, m-1, b[i]);
//         if(sm_index == -1) {
//             result += a[0] - b[i];
//         } else if(la_index == -1) {
//             result += b[i] - a[m-1];
//         } else {
//             int temp = min(abs(b[i] - a[sm_index]), abs(b[i] - a[la_index]));
//             result += temp;
//         }
//     }
//     cout << result;
//     return 0;
// }


//优化使用lower_bound
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    vector<int>a(m), b(n);
    for(int i = 0;i < m;i++) {
        cin >> a[i];
    }
    for(int i = 0;i < n;i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    long long result = 0;
    for(int i = 0;i < n;i++) {
        //lower_bound返回的是第一个大于等于b[i]对应的迭代器
        auto index = lower_bound(a.begin(), a.end(), b[i]);
        if(index == a.end()) {
            //没有找到比b[i]大的数字
            result += b[i] - a[m-1];
        } else if(index == a.begin()) {
            //第一个分数就是大于b[i]的，也就是全部的分数都是大于b[i]
            result += a[0] - b[i];
        } else {
            result += min(abs(*index - b[i]), abs(*(index-1) - b[i]));
        }
    }
    cout << result;
    return 0;
}