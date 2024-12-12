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
    bool isPalindrome(ListNode* head) {
        if(head==NULL || head->next==NULL)return true;
        ListNode* temp = head;
        int size = 0;
        while(temp!=NULL){
            temp =temp->next;
            size++;
        }
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast ->next -> next;
        }
            ListNode* first = head;
            ListNode* second = head->next;
            ListNode* third = head->next->next;
                first->next = NULL;
            while(second!=slow){
                second->next = first;
                first = second;
                second = third;
                third = third->next;
            }
            if(size%2!=0)second = second->next;
            while(first!=NULL){
                if(first->val != second->val)return false;
                first = first->next;
                second = second->next;
            }
            return true;;
    }
};