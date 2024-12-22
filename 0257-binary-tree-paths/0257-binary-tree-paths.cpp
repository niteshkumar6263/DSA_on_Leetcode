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
    void allpath(TreeNode* root, vector<string>& ans, string s){
        if(root==NULL)return;
        s+=(to_string(root->val))+"->";
        allpath(root->left, ans,s);
        allpath(root->right,ans,s);
        if(root->left==NULL && root->right==NULL){
            s.pop_back();
            s.pop_back();
            ans.push_back(s);
        }
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string s;
        allpath(root,ans,s);
        return ans;
    }
};