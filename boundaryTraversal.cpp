#include<bits/stdc++.h>
using namespace std;
struct Node{
    int val;
    struct Node* left;
    struct Node* right;

    Node(int val){
        this->val = val;
        left = right = nullptr;
    }
};

void leftBoundary(struct Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    cout<<root->val;
    if(root->left) leftBoundary(root->left);
    else leftBoundary(root->right);
}

void rightBoundary(struct Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    cout<<root->val;
    if(root->right) leftBoundary(root->right);
    else leftBoundary(root->left);
}

void leafNodes(struct Node* root){
    if(root->left == NULL && root->right == NULL){
        cout<<root->val;
        return;
    }
    leafNodes(root->left);
    leafNodes(root->right);
}

void boundaryTraversal(struct Node* root){
    if(root == NULL) return;
    cout<<root->val;
    leftBoundary(root->left);
    leafNodes(root);
    rightBoundary(root->right);
}
