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
void count(TreeNode* root, int k, int &i, int &ele){
    if(root==NULL)return;
    if(ele==-1)count(root->left,k,i,ele);
    i+=1;
    if(i==k){
        ele = root->val;
        return;
    }
    if(ele==-1)count(root->right,k,i,ele);

}
    int kthSmallest(TreeNode* root, int k) {
        int ele = -1;
        int i = 0;
        count(root,k,i,ele);
        return ele;
    }
};