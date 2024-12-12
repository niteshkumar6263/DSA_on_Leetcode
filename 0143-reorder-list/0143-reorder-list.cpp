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
    ListNode* reverse(ListNode* head){
        if(head==NULL || head->next==NULL)return head;
        ListNode* newhead = reverse(head->next);
        ListNode* front = head->next;
        head->next = NULL;
        front->next = head;
        return newhead;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)return;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* head2 = reverse(slow->next);
        slow->next = NULL;
        ListNode* head1 = head->next;
        ListNode* temp = head;
        while(head2!=NULL){
            temp->next = head2;
            head2 = head2->next;
            temp = temp->next;
            temp->next = head1;
            head1 = head1->next;
            temp = temp->next;
        }
        return;
    }
};