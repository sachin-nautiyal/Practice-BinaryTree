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

int maximumPathSum(struct Node* root, int &maxiSum){
    if(root == NULL) return 0;

    int left = max(0, maximumPathSum(root->left, maxiSum));
    int right = max(0, maximumPathSum(root->right, maxiSum));

    int sum = left + right + root->val;
    maxiSum = max(maxiSum, sum);

    return root->val + max(left, right);
}
