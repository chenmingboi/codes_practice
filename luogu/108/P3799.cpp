#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll kMod = 1e9 + 7;

ll c(ll num) {
    return num * (num - 1) / 2;
}

int main() {
    int n;
    cin >> n;
    vector<int>a(n, 0);
    unordered_map<int, ll>freq;
    for(int i = 0;i < n;i++) {
        cin >> a[i];
        freq[a[i]]++;
    }
    vector<int>changdu;
    for(const auto& it : freq) {
        changdu.push_back(it.first);
    }
    sort(changdu.begin(), changdu.end());
    ll result = 0;
    //假设四个木棍长度为i,j,s,s分为两种情况
    //第一种i == j, 第二种i < j
    //枚举两根相等的边
    for(const auto& s : changdu) {
        if(freq[s] >= 2) {
            //枚举来两根比较短的边
            for(const auto& i : changdu) {
                if(s > i) {
                    //i < j，j = s-i
                    if(freq[s-i] > 0 && i < s-i) { 
                        //注意这里的判断条件不能写成i != s-i
                        //因为这样的话会重复计算，比如前面计算了i = 2, j = 3
                        //到后面会重复计算i = 3, j = 2;
                        //要限制一边
                        result += freq[i] * freq[s-i] * c(freq[s]);
                    } else if (freq[s-i] > 0 && i == s-i && freq[i] >= 2) {
                        //i == j
                        result += c(freq[i]) * c(freq[s]);
                    }
                }
                
            }
        }
    }
    result %= kMod;
    cout << result;
    return 0;
}