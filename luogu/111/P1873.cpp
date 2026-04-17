#include<bits/stdc++.h>
using namespace std;

int erfen(const vector<int>& height, const int& l, const int& r, const int& m, const int &n) {
    int mid = l + (r - l) / 2;
    if(l > r) {
        return -1;
    }
    //所有树的高度总和大于int的范围
    long long sum = 0;
    for(int i = n-1;i >= 0;i--) {
        if(height[i] >= mid){
            sum += height[i] - mid;
        } else {
            break;
        }
    }
    if(sum >= m) {
        //如果已经大于等于，尝试更高的高度，如果没有更高的高度符合条件返回当前高度
        int ans = erfen(height, mid+1, r, m, n);
        if(ans != -1) {
            return ans;
        } else {
            return mid;
        }
    } else if(sum < m) {
        return erfen(height, l, mid-1, m, n);
    }
}
int main() {
    int n, m;
    cin >> n >> m;
    int maxHeight = 0;
    vector<int>height(n);
    for(int i = 0;i < n;i++) {
        cin >> height[i];
        maxHeight = max(maxHeight, height[i]);
    }
    sort(height.begin(), height.end());
    int ans = 0;
    cout << erfen(height, 0, maxHeight, m, n);
    return 0;

}
// //TLE
// void change(vector<long long>&total, const int& h) {
//     for(int i = 1;i <= h;i++) total[i]++;
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, m;
//     cin >> n >> m;
//     int maxheight = 0;
//     vector<int>height(n);
//     vector<long long>total(400005);
//     for(int i = 0;i < n;i++) {
//         cin >> height[i];
//         change(total, height[i]);
//         maxheight = max(maxheight, height[i]);
//     }
//     int result = 0;
//     int sum = 0;
//     for(int i = maxheight;i >= 1;i--) {
//         sum += total[i];
//         if(sum >= m) {
//             result = i-1;
//             break;
//         }
//     }
//     cout << result;
//     return 0;
// }