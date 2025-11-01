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

int diameter(struct Node* root,int &dia){
    if(root == NULL) return 0;
    int left = diameter(root->left,dia);
    int right = diameter(root->right,dia);
    dia = max(dia,left+right);
    return max(left,right)+1;
}