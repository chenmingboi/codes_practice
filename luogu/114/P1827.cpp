#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const string& inOrder, const string& preOrder, int in_start, int in_end, int& root_index_pre) {
    if(in_start > in_end) return nullptr;
    // 创建根节点
    char root_val = preOrder[root_index_pre++];//下一个root就是前序遍历的下一个值
    int root_index_in = inOrder.find(root_val); //返回第一次查找到root_val的下标
    TreeNode* root = new TreeNode(root_val);
    // 递归构造左子树和右子树
    root->left = buildTree(inOrder, preOrder, in_start, root_index_in-1, root_index_pre);
    root->right = buildTree(inOrder, preOrder, root_index_in+1, in_end, root_index_pre);
    return root;
}

void postOrder(TreeNode* root) {
    if(root == nullptr) return;
    if(root->left != nullptr) postOrder(root->left);
    if(root->right != nullptr) postOrder(root->right);
    cout << root->val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string inOrder, preOrder;
    cin >> inOrder >> preOrder;
    int len = inOrder.size(), root_index = 0;
    TreeNode* root;
    root = buildTree(inOrder, preOrder, 0, len-1, root_index);
    postOrder(root);
    return 0;
}