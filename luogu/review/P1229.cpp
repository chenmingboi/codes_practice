// #include<bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     string preorder, postorder;
//     cin >> preorder >> postorder;
//     int len = preorder.length();
//     long long ans = 1LL;
//     //preorder 中出现ab, postorder对应位置出现ba即当前节点a只有一个child
//     //只有一个child的时候其中序遍历就有两种遍历方式
//     for(int i = 0;i < len;i++) {
//         for(int j = 1;j < len;j++) {
//             if(preorder[i] == postorder[j] &&
//                 preorder[i+1] == postorder[j-1]) {
//                     ans *= 2;
//                 }
//         }
//     }
//     cout << ans;
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    int len = s1.length();
    long long result = 1LL;
    for(int i = 0;i < len-1;i++) {
        for(int j = 1;j < len;j++) {
            if(s1[i] == s2[j] && s1[i+1] == s2[j-1]) {
                result *= 2;
            }
        }            
    }
    cout << result;
    return 0;
}