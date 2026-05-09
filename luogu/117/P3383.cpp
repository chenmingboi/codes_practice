#include<bits/stdc++.h>
using namespace std;

//欧拉筛
vector<int>pri;
vector<bool>not_prime;

void pre(int n) {
    for(int i = 2;i <= n;i++) {
        if(!not_prime[i]) pri.push_back(i);
        for(int pri_j : pri) {
            if(i * pri_j > n) break;
            not_prime[i * pri_j] = true;
            if(i % pri_j == 0) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    not_prime.resize(n+1, false);
    pre(n);
    for(int i = 0;i < q;i++) {
        int k;
        cin >> k;
        cout << pri[k-1] << endl;
    }
    return 0;
}

// int n;
// vector<int>sushu;

// bool isSushu(int num) {
//     if(num <= 1) return false;
//     if(num == 2 || num == 3) return true;
//     if(num % 2 == 0 || num % 3 == 0) return false;
//     for(int i = 4;i * i <= num;i++) {
//         if(num % i == 0) return false;
//     }
//     return true;
// }
// void addSushu() {
//     for(int i = 2;i <= n;i++) {
//         if(isSushu(i)) {
//             sushu.push_back(i);
//         }
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int q;
//     cin >> n >> q;
//     //TLE
//     addSushu();
//     for(int i = 0;i < q;i++) {
//         int num;
//         cin >> num;
//         cout << sushu[num-1] << endl;
//     }
//     return 0;
// }