#include<bits/stdc++.h>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val = val;
        left = right = nullptr;
    }
};


vector<int> topView(TreeNode* root){
    if(root == NULL) return {};
    map<int,int> mp;
    queue<pair<TreeNode*,int>> Q;
    Q.push({root,0});
    while(!Q.empty()){
        int idx = Q.front().second;
        TreeNode* node = Q.front().first;
        Q.pop();
        if(!mp.count(idx)){
            mp[idx] = node->val;
        }
        if(node->left) Q.push({node->left,idx-1});
        if(node->right) Q.push({node->right,idx+1});
    }

    vector<int> ans;
    for(auto& m : mp){
        ans.push_back(m.second);
    }
    
    return ans;
}