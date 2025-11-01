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

//time complexity O(n*n)
// int height(struct Node* root){
//     if(root == NULL) return 0;
//     int left = height(root->left);
//     int right = height(root->right);
//     return max(left,right)+1;
// }
// bool checkBalancedBinaryTree(struct Node* root){
//     if(root == NULL) return true;
//     int left = height(root->left);
//     int right = height(root->right);
//     if(!checkBalancedBinaryTree(root->left)) return false;
//     if(!checkBalancedBinaryTree(root->right)) return false;
//     if(abs(left-right) > 1) return false;
//     return true;
// }

int checkBalancedBinaryTree(struct Node* root){
    if(root == NULL) return 0;
    int left = checkBalancedBinaryTree(root->left);
    if(left == -1) return -1;
    int right = checkBalancedBinaryTree(root-right);
    if(right == -1) return -1;
    if(abs(left-right) > 1) return -1;
    return max(left,right) + 1;
}