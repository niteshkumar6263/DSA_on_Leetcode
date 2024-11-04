/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* temp = head;
        map<ListNode*, int>m;
        while(temp!=NULL){
            m[temp]++;
            if(m[temp]==2)return temp;
            temp = temp->next;
        }
        return NULL;
    }
};