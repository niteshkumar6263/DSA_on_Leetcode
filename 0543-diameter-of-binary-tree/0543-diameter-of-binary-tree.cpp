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
    int longestpath(TreeNode* root, int&  maxi){
        if(root==NULL)return 0;
        int leftr = longestpath(root->left,maxi);
        int rightr = longestpath(root->right,maxi);
        maxi = max(maxi,leftr+rightr);
        return 1+max(leftr,rightr);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        longestpath(root,maxi);
        return maxi;
    }
};