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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(left == right)return head;
        if(head->next == NULL)return head;
        ListNode* l;
        ListNode* r;
        int size = 0;
        ListNode* temp  = head;
        while(temp!=NULL){
            size++;
            if(size==left)l = temp;
            if(size == right) r= temp;
            temp = temp->next;
        }
        ListNode* first = l;
        ListNode* second = l->next;
        ListNode* third =  l->next->next;
        first->next = r->next;
        while(first!=r){
            second->next = first;
            first = second;
            second = third;
            if(first == r)break;
            third = third->next;
        }
        if(left==1)return r;
        temp = head;
        while(temp->next!=l){
            temp = temp->next;
        }
        temp->next = r;
        return head;
    }
};