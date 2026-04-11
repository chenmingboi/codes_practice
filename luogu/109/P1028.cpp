#include<bits/stdc++.h>
using namespace std;

//TLE 问题在于会重复计算
// long long result = 1;
// void digui(int last_num) {
//     if(last_num / 2 == 0) {
//         return;
//     }
//     for(int j = last_num/2;j >= 1;j--) {
//         result++;
//         digui(j);
//     }
//     return;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     digui(n);
//     cout << result;
//     return 0;
// }

//尝试用数组存储中间结果
// 记忆化搜索
//其实对应的函数关系为f(x) = 1 + sum_(i=1)^(x/2)f(i)
// vector<long long>result(1005, 0);
// long long digui(int i) {
//     if(result[i] != 0) return result[i];
//     long long ans = 1;
//     for(int j = i/2;j>= 1;j--) {
//         ans += digui(j);
//     }
//     return result[i] = ans;//赋值加返回
//     /*
//     相当于
//     result[i] = ans;
//     return ans;
//     在c++中赋值语句是有返回值的, eg. a=b返回值是b
//     */
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n;
//     cin >> n;
//     result[1] = 1;
//     digui(n);
//     cout << result[n];
//     return 0;
// }

//由对应的函数关系可以知道f(x)只依赖于小于x的对应f,
//所以也可以用递推dp

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<long long>f(1005, 1);
    for(int i = 1;i <= n;i++) {
        for(int j = 1;j <= i/2;j++) {
            f[i] += f[j];
        }
    }
    cout << f[n];
    return 0;
}