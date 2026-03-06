#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m=0, t=0, s=0;
    cin >> m >> t >> s;
    if(t == 0) {
        cout << 0;
    } else {
        cout << max((s%t == 0) ? (m - s/t) : (m - s/t - 1), 0);
    }
    /*
    // 假设 s=10, t=3
    ceil(s/t)  
    // s/t 先算 → 10/3 = 3（整数除法，直接截断！）
    // ceil(3) → 3.0（已经是整数了，向上取整没用）
    // 正确应该是 ceil(10/3.0) = ceil(3.333...) = 4
    max(m - (int)ceil((double)s / t), 0);
    */
    return 0;
}