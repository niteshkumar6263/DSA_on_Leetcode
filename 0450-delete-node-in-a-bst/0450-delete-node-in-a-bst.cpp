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
    // TreeNode* findpre(TreeNode* root){
    //     if(root->left==NULL){
    //         return NULL;
    //     }
    //     TreeNode* pre = root->left;
    //     while(pre->right!=NULL)pre = pre->right;
    //     return pre->val;
    // }
    TreeNode* findsuc(TreeNode* root){
        if(root->right==NULL){
            return NULL;
        }
        TreeNode* succ = root->right;
        while(succ->left!=NULL)succ = succ->left;
        return succ;
    }
    TreeNode* del(TreeNode* root,int key, bool& flag){
        if(root==NULL)return NULL;
        if(root->val < key){
            TreeNode* temp =  del(root->right, key,flag);
            if(flag){
                root->right = temp;
                flag  = false;
            }
        }
        else if(root->val>key){
            TreeNode* temp =  del(root->left,key,flag);
            if(flag){
                root->left = temp;
                flag = false;
            }
        }
        else{
            if(root->left == NULL && root->right == NULL){
                flag = true; 
                return NULL;
            }
            else if(root->left == NULL){
                flag = true; 
                return root->right;
            }
            else if(root->right ==NULL){
                flag = true; 
                return root->left;
            }
            else{
                TreeNode* suc = findsuc(root);
                suc->left  =  root->left;
                flag = true;
                return root->right;
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)return NULL;
        bool flag = false;
        return del(root,key,flag);
    }
};