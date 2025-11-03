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

vector<vector<int>> zigzagTraversal(struct Node* root){
    if(root == NULL) return {}; 
    queue<struct Node*> Q;
    vector<vector<int>> ans;
    Q.push(root);
    int leftToRight = 1;
    while(!Q.empty()){
        int n = Q.size();
        vector<int> temp(n);
        for(int i=0;i<n;i++){
            struct Node* node = Q.front();
            Q.pop();

            if(node->left) Q.push(node->left);
            if(node->right) Q.push(node->right);

            int idx = (leftToRight) ? i : (n-1-i);
            temp[idx] = node->val;
        }
        ans.push_back(temp);
    }
    return ans;
}