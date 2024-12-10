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
    ListNode* reverseList(ListNode* head) {
        if(head ==NULL || head->next == NULL)return head;
        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* third = head->next->next;
            first->next = NULL;
        while(second!=NULL){
            second->next = first;
            first = second;
            second = third;
            if(second==NULL)return first;
            third = third->next;
        }
        return NULL;
    }
};