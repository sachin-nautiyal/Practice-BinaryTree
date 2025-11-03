#include<bits/stdc++.h>
using namespace std;
struct Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

//using DFS
void solve(Node* root, int v, int h, map<int, pair<int, int>>& mp) {
    if (root == NULL) return;

    solve(root->left, v - 1, h + 1, mp);
    solve(root->right, v + 1, h + 1, mp);

    
    if (mp.find(v) == mp.end() || h >= mp[v].first) {
        mp[v] = {h, root->data};
    }
}
    vector<int> bottomView(Node *root) {
        
        map<int, pair<int, int>> mp;
        solve(root,0,0,mp);
        vector<int> ans;
        for(auto& m : mp){
            auto& p = m.second;
            ans.push_back(p.second);
        }
        return ans;
    }

//BFS(level order Traversal)

vector<int> bottomView(Node* root) {
    if (root == NULL) return {};

    queue<pair<Node*, int>> Q;  // node, vertical index
    map<int, int> mp;           // vertical -> node value

    Q.push({root, 0});

    while (!Q.empty()) {
        Node* node = Q.front().first;
        int idx = Q.front().second;
        Q.pop();

        // store or update the latest node at this vertical
        mp[idx] = node->data;

        if (node->left) Q.push({node->left, idx - 1});
        if (node->right) Q.push({node->right, idx + 1});
    }

    vector<int> ans;
    for (auto& m : mp) ans.push_back(m.second);
    return ans;
}
