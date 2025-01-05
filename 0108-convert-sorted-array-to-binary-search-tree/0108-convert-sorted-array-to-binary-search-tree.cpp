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
    TreeNode* create(vector<int>v){
        if(v.size()==0)return NULL;
        int n = v.size();
        int mid = n/2;
        TreeNode* root = new TreeNode(v[mid],NULL,NULL);
        vector<int>l;
        vector<int>r;
        for(int i =0;i<mid;i++) l.push_back(v[i]);
        for(int i = mid+1;i<n;i++)r.push_back(v[i]);
        root->left = create(l);
        root->right = create(r);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums);
    }
};