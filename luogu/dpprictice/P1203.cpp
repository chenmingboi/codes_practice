#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    string s;
    cin >> s;
    //将s进行扩展成2s这样就可以枚举区间[i, i+n-1]这样就是一个完整的圆环
    //这样从i~i+n-1就是一条拆分开的项链
    s += s;
    int ans = 0;
    //枚举每一个断点，假设是在i和i+1之间断开，左侧区域对应的是[]
    for(int i = 0;i < n;i++) {
        int left = 0, right = 0;
        //向左遍历
        char color = 'w';//要收集的颜色，初始未知
        for(int j = i+n;j > i;j--) {
            char cur = s[j];
            if(color == 'w') {
                if(cur != 'w') {
                    color = cur;
                }
                left++;
            } else {
                if(cur == color || cur == 'w'){
                    left++;
                } else {
                    break;
                }
            }
        }
        color = 'w';
        for(int j = i+1;j <= i+n;j++) {
            char cur = s[j];
            if(color == 'w') {
                if(cur != color) color = cur;
                right++;
            } else {
                if(cur == color || cur == 'w') {
                    right++;
                } else {
                    break;
                }
            }
        }
        ans = max(ans, min(right + left, n));
    }
    cout << ans;
    return 0;
}