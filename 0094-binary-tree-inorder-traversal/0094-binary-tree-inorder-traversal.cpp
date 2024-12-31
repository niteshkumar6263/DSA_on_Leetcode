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
    vector<int> inorderTraversal(TreeNode* root) {
       TreeNode* node = root;
       vector<int>ans;
       stack<TreeNode*>st;
       if(node==NULL)return ans;
       while(true){
        if(node!=NULL){
            st.push(node);
            node = node->left;
        }
        else {
            if(node==NULL && st.empty())break;
            TreeNode* temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            node = temp->right;
        }
       }
       return ans;
    }
};