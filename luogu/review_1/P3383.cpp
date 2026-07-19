#include<bits/stdc++.h>
using namespace std;

vector<int>prime;
vector<bool>not_prime;

void oula(int n) {
    for(int i = 2;i <= n;i++) {
        if(!not_prime[i]) prime.push_back(i);
        for(int j : prime) {
            if(i * j > n) break;
            not_prime[i * j] = true;
            if(i % j == 0) break;
        }
    }
}
//使用欧拉筛
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    not_prime.resize(n+1, false);
    oula(n);
    for(int i = 0;i < q;i++) {
        int k;
        cin >> k;
        cout << prime[k-1] << '\n';
    }
    return 0;
}
//TLE
// bool isPrime(int num) {
//     if(num == 2 || num == 3) return true;
//     if(num % 2 == 0 || num % 3 == 0 || num == 1) return false;
//     for(int i = 5;i * i <= num;i++) {
//         if(num % i == 0) return false;
//     }
//     return true;
// }

// void addsushu(vector<int>& sushu, int begin, int k, int n) {
//     int cha = k - sushu.size() + 1;
//     for(int i = begin+1;i <= n;i++) {
//         if(isPrime(i)) {
//             sushu.push_back(i);
//             cha--;
//             if(cha == 0) break;
//         }
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n, q;
//     cin >> n >> q;
//     vector<int>sushu(1, 0);
//     for(int i = 0;i < q;i++) {
//         int k;
//         cin >> k;
//         if(k > sushu.size()-1) {
//             addsushu(sushu, sushu[sushu.size()-1], k, n);
//         }
//         cout << sushu[k] << '\n';
//     }
//     return 0;
// }