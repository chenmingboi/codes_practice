#include<bits/stdc++.h>
using namespace std;

string inOrder, preOrder;
struct Node{
    char val;
    Node* left;
    Node* right;
};

Node* buildTree(int& prerootIndex, int left, int right) {
    char value = preOrder[prerootIndex];
    int inrootIndex = find(inOrder.begin(), inOrder.end(), value) - inOrder.begin();
    if(inrootIndex < left || inrootIndex >= right) return nullptr;
    Node* root = new Node;
    root->val = value;
    prerootIndex += 1;
    root->left = buildTree(prerootIndex, left, inrootIndex);
    root->right = buildTree(prerootIndex, inrootIndex+1, right);
    return root;
}

void postOrder(Node* root) {
    if(root == nullptr) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> inOrder >> preOrder;
    Node* root = nullptr;
    int index = 0;
    root = buildTree(index, 0, inOrder.size());
    postOrder(root);
    return 0;
}