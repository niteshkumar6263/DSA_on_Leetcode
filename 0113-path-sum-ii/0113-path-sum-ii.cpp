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
void cal(TreeNode* root,vector<vector<int>> &ans, vector<int>v, int sum, int &targetSum){
    if(root==NULL)return;
    v.push_back(root->val);
    if(root->left ==NULL && root->right == NULL){
        if(sum+root->val==targetSum){
            ans.push_back(v);
        }
        return;
    }
    cal(root->left, ans,v, sum+root->val, targetSum);
    cal(root->right, ans,v, sum+root->val, targetSum);
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        int sum = 0;
        if(root == NULL)return ans;
        vector<int>v;
        cal(root, ans, v, sum, targetSum);
        return ans;
    }
};