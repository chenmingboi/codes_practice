#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    //对于一棵二叉树，如果某个节点只有一个孩子，那么这个孩子可以是左孩子，也可以是右孩子。
    //这两种情况的前序和后序遍历完全一样，但中序遍历不同。
    //如果一个节点只有一个孩子(此时假设前序遍历中缺左，那么后序遍历也缺左，
    //所以此时前序遍历两个元素和后序遍历两个元素恰好相反)，如果有两个孩子则不会出先这种情况
    //前序遍历：root 左 右
    //后续遍历：左 右 root
    string s1, s2;
    cin >> s1 >> s2;
    int len = s1.length(), cnt = 0;
    for(int i = 0;i < len-1;i++) {
        for(int j = 0;j < len-1;j++) {
            if(s1[i] == s2[j+1] && s1[i+1] == s2[j]) cnt++;
        }
    }
    long long ans = 1;
    while(cnt) {
        ans *= 2; cnt--;
    }
    cout << ans;
    return 0;
}