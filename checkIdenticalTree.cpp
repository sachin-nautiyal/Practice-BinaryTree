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


bool checkIdenticalTree(struct Node* root1,struct Node* root2){
    if(root1 == NULL || root2 == NULL){
        return root1 == root2;
    }
    if(root1->val != root2->val) return false;
    if(!checkIdenticalTree(root1->left,root2->left)) return false;
    if(!checkIdenticalTree(root1->right,root2->right)) return false;
    return true;
}