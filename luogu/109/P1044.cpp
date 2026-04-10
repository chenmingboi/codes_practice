#include<bits/stdc++.h>
using namespace std;

//递归的方法的最后一个样例TLE
//只有两种操作Push和pop，当pop出来的数字个数等于n的时候停止递归
// int n, result = 0, num_push, num_pop;
// void digui(int i) {
//     //这里的i为操作次数，每个数字都要经过Push和pop，即两次操作
//     if(i == 2*n) {
//         result++;
//         return;
//     }
//     //push，操作数队列数字减少
//     if(num_push) {
//         num_push--;
//         digui(i+1);
//         num_push++;
//     }
//     if(num_pop && num_pop > num_push) {
//         num_pop--;
//         digui(i+1);
//         num_pop++;
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     cin >> n;
//     num_push = n, num_pop = n;
//     digui(0);
//     cout << result;
//     return 0;
// }

//emmm，看了题解，可以使用卡特兰数C_n = (4n-2)*C_(n-1) / (n+1);
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    long long result = 1;
    for(int i = 2;i <= n;i++) {
        result = (4 * i - 2) * result / (i + 1);
    }
    cout << result;
    return 0;
}