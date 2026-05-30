#include<bits/stdc++.h>
using namespace std;

vector<int>use = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int use_num(int num) {
    int ans = 0;
    if(use[num]) {
        return use[num];
    }
    int tempnum = num;
    while(num) {
        int temp = num % 10;
        ans += use[temp];
        num /= 10;
    }
    use[tempnum] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    use.resize(2223);
    int ans = 0;
    //n小于24此时两个加数不超过1111
    for(int i = 0;i <= 1111;i++) {
        for(int j = 0;j <= 1111;j++) {
            int a = use_num(i);
            int b = use_num(j);
            int c = use_num(i+j);
            if(a+b+c+4 == n) {
                ans++;
            }
        }
    }
    cout << ans;
    return 0;
}