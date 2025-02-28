#include <bits/stdc++.h>
using namespace std;

class tree {
public :     
    int val;
    tree* left;
    tree* right;
    
    tree(int val){
        this->val = val;
        left = right = NULL;
    }
};

void solveInorderTraversal(vector<int> &ans,TreeNode* root){    // inorder traversal same we can do for pre order and post order 
    if(root == NULL)return;
    solveInorderTraversal(ans,root->left);
    ans.push_back(root->val);
    solveInorderTraversal(ans,root->right);
}


int main(){
    tree* tushar = new tree(6);
    cout <<tushar->val<<endl;
    return 0;
}