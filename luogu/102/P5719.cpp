#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int>a ,b; //这里可以不同数组，直接将result_a, result_b加上对应的i就可以了
    for(int i = 1;i <= n;i++){
        if(i % k == 0) {
            a.emplace_back(i);
        } else {
            b.emplace_back(i);
        }
    }
    double result_a = 0.0, result_b = 0.0;
    for(auto it : a) {
        result_a += it;
    }
    for(auto it : b) {
        result_b += it;
    }
    result_a = result_a/a.size();
    result_b = result_b/b.size();
    cout << fixed << setprecision(1) << result_a << ' ' << result_b;
    // ostringstream oss;
    // oss << fixed << setprecision(1) << result_a << ' ' << result_b;
    // cout << oss.str();
}