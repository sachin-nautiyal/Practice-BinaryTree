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

int maxiDepth(struct Node* root){
    if(root == NULL) return 0;
    int left = maxiDepth(root->left);
    int right = maxiDepth(root->right);
    return max(left,right)+1;
}