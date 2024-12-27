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
    int levels(TreeNode* root){
        if(root==NULL)return 0;
        return 1+max(levels(root->left), levels(root->right));
    }
    void nthlevel1(TreeNode* root, int curr, int level,vector<int>&v){
        if(root==NULL)return;
        if(curr==level){
            v.push_back(root->val);
            return;
        }
        nthlevel1(root->left,curr+1,level,v);
        nthlevel1(root->right,curr+1,level,v);
    }
    void nthlevel2(TreeNode* root, int curr, int level,vector<int>&v){
        if(root==NULL)return;
        if(curr==level){
            v.push_back(root->val);
            return;
        }
        nthlevel2(root->right,curr+1,level,v);
        nthlevel2(root->left,curr+1,level,v);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        int n = levels(root);
        vector<vector<int>>ans;
        for(int i =1;i<=n;i++){
            vector<int>v;
           if(i%2==0)nthlevel2(root,1,i,v);
           else nthlevel1(root,1,i,v);
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};