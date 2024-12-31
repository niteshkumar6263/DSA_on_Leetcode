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
    bool check(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* & ans){
        if(root==NULL)return false;
        bool leftr = check(root->left,p,q,ans);
        bool rightr = check(root->right,p,q,ans);
        if((leftr && rightr) || ((leftr || rightr) && (root==p || root==q))){
            ans = root;
            return false;
        }
        if(leftr || rightr || root==p || root==q)return true;
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        check(root,p,q,ans);
        return ans;
    }
};