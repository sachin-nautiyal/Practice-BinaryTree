
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

/*depth fist search
1. inorder
2. preorder
3. postorder
*/
//inorder Traversal (left root right)
void inorderTraversal(struct Node* root){
    if(root == NULL) return;
    inorderTraversal(root->left);
    cout<<root->val<<" ";
    inorderTraversal(root->right);
}

//pre-order Traversal (root left right)
void preorderTraversal(struct Node* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

//post-order Traversal (left right root)
void postorderTraversal(struct Node* root){
    if(root == NULL) return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout<<root->val<<" ";
}


//Breadth first Search
void bfs(struct Node* root){
    if(root == NULL) return;
    queue<struct Node*> Q;
    Q.push(root);
    
    while(!Q.empty()){
        int n = Q.size();
        for(int i=0;i<n;i++){
            struct Node* node = Q.front();
            Q.pop();
            cout<<node->val;
            if(node->left) Q.push(node->left);
            if(node->right) Q.push(node->right);
        }
    }
}

