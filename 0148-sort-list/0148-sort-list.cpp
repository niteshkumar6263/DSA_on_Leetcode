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
    ListNode* mergesort(ListNode* list1, ListNode* list2){
        if(list1 == NULL)return list2;
        if(list2 == NULL)return list1;
        ListNode* start = list1;
        if(list1->val<=list2->val){
            start = list1;
            list1 = list1->next;
        }
        else{
            start = list2;
            list2 = list2->next;
        }
        ListNode* ptr = start;
        while(list1 && list2){
            if(list1->val <= list2->val){
                start->next = list1;
                list1 = list1->next;
            }
            else{
                start->next = list2;
                list2 = list2 -> next;
            }
            start = start -> next ;
        }
        if(list1 == NULL)start->next = list2;
        else start->next = list1;
        return ptr;
    }
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)return head;
        ListNode* slow = head ;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* a = head;
        ListNode* b = slow->next;
        slow->next = NULL;
        a = sortList(a);
        b = sortList(b);
        return mergesort(a, b);
    }
};