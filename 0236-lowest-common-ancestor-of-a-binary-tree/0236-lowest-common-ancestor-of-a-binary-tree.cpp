/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: 
    bool find(TreeNode* root, TreeNode* f){
        if(root==NULL)return false;
        if(root->val == f->val)return true;
        return find(root->left,f) || find(root->right,f);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==p || root ==q)return root;
        else if(find(root->left,p) && find(root->right,q))return root;
        else if(find(root->right,p) && find(root->left,q))return root;
        else if(find(root->right,p) && find(root->right,q))return lowestCommonAncestor(root->right,p,q);
        else return lowestCommonAncestor(root->left,p,q);
    }
};