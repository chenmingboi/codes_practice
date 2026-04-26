#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    char val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* search(TreeNode* root, const char& val) {
    if(root == nullptr) return nullptr;
    if(root->val == val) return root;
    TreeNode* left_result = search(root->left, val);
    if(left_result != nullptr) return left_result;
    return search(root->right, val);
}
TreeNode* buildTree(TreeNode* root, char parent_val, char left_val, char right_val) {
    if(root == nullptr) {
        root = new TreeNode(parent_val);
    }
    TreeNode* parentNode = search(root, parent_val);
    TreeNode* leftNode = ((left_val == '*') ? nullptr : search(root, left_val));
    TreeNode* rightNode = ((right_val == '*') ? nullptr : search(root, right_val));
    if(parentNode == nullptr) {
        parentNode = new TreeNode(parent_val);
    }
    if(leftNode == nullptr && left_val != '*') {
        leftNode = new TreeNode(left_val);
    }
    if(rightNode == nullptr && right_val != '*') {
        rightNode = new TreeNode(right_val);
    }
    parentNode->left = leftNode;
    parentNode->right = rightNode;
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
    int n;
    cin >> n;
    TreeNode* root = nullptr;
    for(int i = 0;i < n;i++) {
        char root_val, left_val, right_val;
        cin >> root_val >> left_val >> right_val;
        root = buildTree(root, root_val, left_val, right_val);
    }
    preOrder(root);
    return 0;
}