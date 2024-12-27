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
    void nthlevel(TreeNode* root, int curr, int level,double & sum,double & count){
        if(root==NULL)return;
        if(curr==level){
            sum+=(double)root->val;
            count++;
            return;
        }
        nthlevel(root->left,curr+1,level,sum,count);
        nthlevel(root->right,curr+1,level,sum,count);
    }
    vector<double> averageOfLevels(TreeNode* root) {
        int n = levels(root);
        vector<double>ans;
        if(root==NULL)return ans;
        for(int i =1;i<=n;i++){
            double sum = 0;
            double count = 0;
            nthlevel(root,1,i,sum,count);
            sum /= count;
            ans.push_back(sum);
        }
        return ans;
    }
};