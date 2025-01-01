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
    void cnt(TreeNode* root, int & targetSum,long long sum, int & count){
        if(root==NULL)return;
        sum+=root->val;
        if(sum==targetSum){
            count+=1;
        }
        cnt(root->left,targetSum,sum,count);
        cnt(root->right,targetSum,sum,count);
        
    }
    void cal(TreeNode* root, int & targetSum,int &count){
        if(root==NULL)return;
        cnt(root, targetSum,0,count);
        cal(root->left,targetSum,count);
        cal(root->right,targetSum,count);

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL)return 0;
        int count = 0 ;
        cal(root,targetSum,count);
        return count;
    }
};