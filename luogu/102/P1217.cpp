#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long a) {
    if(a % 2 == 0 || a % 3 == 0) return false;
    for(int i = 2; i*i <= a;i++) {
        if(a % i == 0) return false;
    }
    return true;
}

bool isHuiwen(long long a){
    string a_str = to_string(a);
    int len = a_str.length();
    for(int i = 0, j = len-1;i < j;i++, j--){
        if(a_str[i] != a_str[j]) return false;
    }
    return true;
}
int main()
{
    int a, b;
    cin >> a >> b;
    vector<int>result;
    for(int i = a; i <= b;i++){
        if(i % 2 == 0) continue;//这道题卡时间，所以尽量减少复杂度，可以先将偶数给全部筛除掉
        if(isHuiwen(i)) { // 然后先判断是否是回文数，回文数比素数要少，减少时间
            if(isPrime(i)) {
                result.push_back(i);
            }
        }
    }
    for(auto it : result) {
        cout << it << endl;
    }
    return 0;
}