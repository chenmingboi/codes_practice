#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int result = 1;
    for(int i = 0;i < n-1;i++) {
        result += 1;
        result *= 2;
    }
    cout << result;
    return 0;
}