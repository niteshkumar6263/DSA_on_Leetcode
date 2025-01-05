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
    void makeit(TreeNode* root, int &sum){
        if(root == NULL)return;
        makeit(root->right, sum);
        root->val = root->val+sum;
        sum = root->val;
        makeit(root->left, sum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        if(root==NULL)return root;
        int sum = 0;
        makeit(root,sum);
        return root;
    }
};