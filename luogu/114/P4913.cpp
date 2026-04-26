#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int bianhao; //节点编号
    int height; //当前节点高度, 本题中高度是指经历的节点数，不是边数，所以初始化为1
    TreeNode* left; //左节点指针
    TreeNode* right; //右节点指针
    TreeNode(int x) : bianhao(x), height(1), left(nullptr), right(nullptr) {}
};

// int maxHeight(TreeNode* root) {
//     int result = root->height;
//     if(root->left) {
//         result = max(maxHeight(root->left)+1, result);
//     }
//     if(root->right) {
//         result = max(maxHeight(root->right)+1, result);
//     }
//     return result;
// }
//上一版maxHeight没有处理root == nullptr,题目中tree[1]保证存在的情况下没事，但是如果n==0
//此时maxHeight将访问一个nullptr, 下面是优化过后的版本

int maxHeight(TreeNode* root) {
    if(root == nullptr) return 0;
    int leftHeight = maxHeight(root->left);
    int rightHeight = maxHeight(root->right);
    return max(leftHeight, rightHeight) + 1;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<TreeNode*>tree(n+1, nullptr);
    for(int i = 1;i <= n;i++) {
        tree[i] = new TreeNode(i);
    }
    for(int i = 1;i <= n;i++) {
        int left_child, right_child;
        cin >> left_child >> right_child;
        if(left_child != 0) {
            tree[i]->left = tree[left_child];
            // tree[left_child]->height += tree[i]->height;
        }
        if(right_child != 0) {
            tree[i]->right = tree[right_child];
            //这里不能在读入的时候进行添加高度，因为可能tree[i]的高度还没有更新
            //前提：父节点一定先于子节点输入。如果题目输入不保证这一点，子节点高度会算错。
            // tree[right_child]->height += tree[i]->height;
        }
    }
    cout << maxHeight(tree[1]);
    //不要忘记释放内存
    for(int i = 1;i <= n;i++) {
        delete tree[i];
    }
    return 0;
}