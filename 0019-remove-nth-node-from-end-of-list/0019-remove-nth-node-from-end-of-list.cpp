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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int size=0;
        ListNode* temp = head;
        while(temp!=NULL){
            size++;
            temp = temp->next;
        }
        int idx=size-n;
        if(idx==0)return head->next;
        temp = head;
        int i=0;
        while(i<idx-1){
            temp=temp->next;
            i++;
        }
        temp->next=temp->next->next;
        return head;
    }
};