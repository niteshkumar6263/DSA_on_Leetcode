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
    bool check(TreeNode* root ,long long& a){
        if(root==NULL)return true;
        bool l =  check(root->left,a);
        if(a >= root->val)return false;
        a = root->val;
        bool r = true;
        if(root->right!=NULL) r = (a>=root->right->val)?false : check(root->right,a);
        return l && r;
    }   
    bool isValidBST(TreeNode* root) {
        long long  a= INT64_MIN;
        return check(root,a);
    }
};