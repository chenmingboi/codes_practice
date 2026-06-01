#include<bits/stdc++.h>
using namespace std;

struct Node {
    char val;
    Node* leftNode;
    Node* rightNode;
};

Node* buildTree(const string& inorder, const string& preorder, int& root_index, int left_bar, int right_bar) {
    if(left_bar > right_bar) return nullptr;
    // if(root_index >= preorder.size()) return nullptr;
    int root_index_in = find(inorder.begin(), inorder.end(), preorder[root_index]) - inorder.begin();
    // if(root_index_in > right_bar || root_index_in < left_bar) return nullptr;
    Node* root = new Node;
    root->val = preorder[root_index];
    root_index += 1;
    root->leftNode = buildTree(inorder, preorder, root_index, left_bar, root_index_in-1);
    // if(root->leftNode == nullptr) root_index -= 1;
    // root_index += 1;
    root->rightNode = buildTree(inorder, preorder, root_index, root_index_in+1, right_bar);
    // if(root->rightNode == nullptr) root_index -= 1;
    return root;
}

void postOrder(Node* root) {
    if(root == nullptr) return;
    postOrder(root->leftNode);
    postOrder(root->rightNode);
    cout << root->val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string inorder, preorder;
    cin >> inorder >> preorder;
    int len = inorder.length();
    int root_index = 0;
    Node* root = buildTree(inorder, preorder, root_index, 0, len-1);
    postOrder(root);
    return 0;
}