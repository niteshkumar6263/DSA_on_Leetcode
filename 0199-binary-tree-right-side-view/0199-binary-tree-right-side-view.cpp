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
    void cal(TreeNode* root, vector<vector<int>>& ans,int level){
        if(root==NULL)return;
        ans[level][0] = root->val;
        cal(root->left,ans,level+1);
        cal(root->right,ans,level+1);
    }
    int level(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(level(root->left),level(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        int n = level(root);
        vector<vector<int>>ans(n,{0});
        vector<int>a;
        if(root==NULL){
            return a;
        }
        cal(root,ans,0);
        for(int i=0;i<ans.size();i++){
            a.push_back(ans[i][0]);
        }
        return a;
    }
};