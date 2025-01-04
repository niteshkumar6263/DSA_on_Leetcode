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
    void insert(TreeNode* root, int val){
        if(val<root->val){
            if(root->left==NULL){
                TreeNode* temp = new TreeNode(val,NULL,NULL);
                root->left = temp;
            }
            else insert(root->left,val);
        }
        else{
            if(root->right ==NULL){
                TreeNode* temp = new TreeNode(val,NULL,NULL);
                root->right = temp;
            }
            else insert(root->right,val);
        }
        return ;

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL){
            TreeNode* temp  = new TreeNode(val,NULL,NULL);
            return temp;
        }
        insert(root,val);
        return root;
    }
};