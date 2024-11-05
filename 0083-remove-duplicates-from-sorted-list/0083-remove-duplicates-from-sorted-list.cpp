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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* start = head;
        ListNode* temp = start;
        while(start!=NULL && start->next!=NULL){
            temp = start;
            while(temp!=NULL && temp->next!=NULL && temp->next->val==temp->val){
                    temp = temp->next;
            }
            start->next = temp->next;
            if(start!=NULL && start->next!=NULL)start = start -> next;
        }
        return head;
    }
};