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

void solve(Node* root, int v, int h, map<int, map<int, multiset<int>>>& mp) {
    if (root == NULL) return;
    mp[v][h].insert(root->val); 
    solve(root->left, v - 1, h + 1, mp);
    solve(root->right, v + 1, h + 1, mp);
}

vector<vector<int>> verticalOrderTraversal(Node* root) {
    map<int, map<int, multiset<int>>> mp;
    solve(root, 0, 0, mp);
    vector<vector<int>> ans;

    for (auto& m : mp) {
        vector<int> temp;
        for (auto& p : m.second) {
            temp.insert(temp.end(), p.second.begin(), p.second.end());
        }
        ans.push_back(temp);
    }
    return ans;
}

int main() {
    Node* root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(4);
    root->left->left = new Node(0);
    root->left->right = new Node(2);
    root->left->right->left = new Node(2);

    vector<vector<int>> res = verticalOrderTraversal(root);
    for (auto& col : res) {
        for (int val : col) cout << val << " ";
        cout << endl;
    }
}



