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
        TreeNode* root = new TreeNode(v[0],NULL,NULL);
        vector<int>l;
        vector<int>r;
        int idx = n;
        for(int i =1;i<n;i++){
            if(v[i]>v[0]){
                idx = i;
                break;
            }
            l.push_back(v[i]);
        }
        for(int i = idx;i<n;i++)r.push_back(v[i]);
        root->left = create(l);
        root->right = create(r);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return create(preorder);
    }
};