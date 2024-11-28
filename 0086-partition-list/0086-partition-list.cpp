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
    ListNode* partition(ListNode* head, int x) {
        ListNode* start = new ListNode(-1, NULL);
         ListNode* start2 = new ListNode(-1, NULL);
        ListNode* small = head;
        ListNode* temp = start;
        ListNode* temp2 = start2;
        while(small != NULL){
            if(small->val<x){
                start->next = small;
                start = start->next;
            }
            else{
                start2->next = small;
                start2 = start2->next;
            }
            small = small -> next;
        }
        start2 -> next =NULL;
        start->next = temp2->next;
        return temp->next;
    }
};