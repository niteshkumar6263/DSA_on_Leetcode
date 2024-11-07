/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>>v(m,vector<int>(n,-1));
        ListNode* temp = head;
        int l=0,t=0;
        int h=n-1,d=m-1;
        while(l<=h && t<=d && temp!=NULL){
            for(int i=l;i<=h && temp!=NULL;i++){
                v[t][i]=temp->val;
                temp = temp->next;
            }
            t++;
            for(int i=t;i<=d && temp!=NULL;i++){
                v[i][h]=temp->val;
                temp = temp->next;
            }
            h--;
            for(int i=h;i>=l && temp!=NULL;i--){
                v[d][i]=temp->val;
                temp = temp->next;
            }
            d--;
            for(int i=d;i>=t && temp!=NULL;i--){
                v[i][l] = temp->val;
                temp = temp->next;
            }
            l++;
        }
        return v;
    }
};