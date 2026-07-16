#include<bits/stdc++.h>
using namespace std;

vector<int>use = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

int usenum(int num) {
    if(use[num]) {
        return use[num];
    }
    int ans = 0, temp = num;
    while(num != 0) {
        int tempnum = num % 10;
        ans += use[tempnum];
        num /= 10;
    }
    use[temp] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, ans = 0;
    cin >> n;
    use.resize(2000);
    for(int i = 0;i < 1000;i++) {
        for(int j = 0;j < 1000;j++) {
            int a = usenum(i), b = usenum(j), c = usenum(i+j);
            if(a+b+c == n-4) ans++;
        }
    }
    cout << ans;
    return 0;
}