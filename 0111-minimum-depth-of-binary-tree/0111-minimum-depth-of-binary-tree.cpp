/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int level(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(level(root->left),level(root->right));
    }
    void count(TreeNode* root, int & mini , int cur){
        if(root==NULL)return;
        if(root->left==NULL && root->right==NULL){
            mini = min(cur,mini);
        }
        count(root->left,mini,cur+1);
        count(root->right,mini,cur+1);
    }
    int minDepth(TreeNode* root) {
        int n = level(root);
        if(root==NULL) return  0 ;
        int mini = INT_MAX;
        count(root,mini,1);
        return mini;
    }
};