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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* temp = head; 
        while(temp!=NULL){
            temp = temp->next;
            size++;
        }
        vector<ListNode*>ans(k,NULL);
        temp = head;
        int i = 0;
        while(size!=0){
            ans[i] = temp;
            int n = ceil((double)size/k);
            int j = 0;
            while(j<n-1){
                temp = temp->next;
                j++;
            }
            ListNode* extra = temp->next;
            temp->next = NULL;
            temp = extra;
            size = size-n;
            k--;
            i++;
        }
        return ans;
    }
};