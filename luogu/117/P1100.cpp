#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string b;
    do {
        int temp = n % 2;
        b += to_string(temp);
        n /= 2;
    } while(b.length() != 32);
    reverse(b.begin(), b.end());
    string part1 = b.substr(0, 16), part2 = b.substr(16, 32);
    string rev_b = part2 + part1;
    reverse(rev_b.begin(), rev_b.end());
    long long result = 0; //这里要用long long因为int的范围是2^31-1，这里result可以取到2^32-1
    for(int i = 0;i < 32;i++) {
        result += (rev_b[i] - '0') * pow(2, i);
    }
    cout << result;
    return 0;
}