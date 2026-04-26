#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const string& inOrder, const string& postOrder, int& root_index_post, int in_start, int in_end) {
    if(in_start > in_end) return nullptr;
    //创建root节点
    char root_val = postOrder[root_index_post--];
    TreeNode* root = new TreeNode(root_val);
    //找到root节点在inOrder中的index
    int root_index_in = inOrder.find(root_val);
    //这里要先构建右子树
    root->right = buildTree(inOrder, postOrder, root_index_post, root_index_in+1, in_end);
    root->left = buildTree(inOrder, postOrder, root_index_post, in_start, root_index_in-1);
    return root;
}

void preOrder(TreeNode* root) {
    if(root == nullptr) return;
    cout << root->val;
    preOrder(root->left);
    preOrder(root->right);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string inOrder, postOrder;
    cin >> inOrder >> postOrder;
    int len = inOrder.length() - 1;
    TreeNode* root = buildTree(inOrder, postOrder, len, 0, len);
    preOrder(root);
    return 0;
}