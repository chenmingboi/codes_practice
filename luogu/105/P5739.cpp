#include<bits/stdc++.h>
using namespace std;

int jicheng(int n) {
    if(n == 1) return 1;
    return n * jicheng(n-1);
}
int main() {
    int n;
    cin >> n;
    cout << jicheng(n);
    return 0;
}