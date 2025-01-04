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
    TreeNode* built(vector<int> preorder, vector<int> inorder){
        TreeNode* root = new TreeNode(preorder[0],NULL,NULL);
        vector<int>in;
        vector<int>pre;
        int idx;
        for(int i = 0;i<inorder.size();i++){
            if(inorder[i]==preorder[0]){
                idx = i;
                break;
            }
        }
        for(int i = 0;i<idx;i++) in.push_back(inorder[i]);
        int k = 1;
        while(k<=in.size())pre.push_back(preorder[k++]);
        if(in.size()>=1){
            root->left = built(pre,in);
        }
        in.clear();pre.clear();
        for(int i = idx+1;i<inorder.size();i++)in.push_back(inorder[i]);
        while(k<preorder.size())pre.push_back(preorder[k++]);
        if(in.size()>=1){
            root->right = built(pre,in);
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return built(preorder, inorder);
    }
};