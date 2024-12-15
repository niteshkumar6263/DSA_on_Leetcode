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
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        if(head == NULL || head->next==NULL || head->next->next==NULL)return head;
        int size = 1;
        ListNode* t = head;
        ListNode* h = head;
            int i = 0;
        while(t!=NULL){
            i=0;
            while(t!=NULL && i<size){
                t = t->next;
                i++;
            }
            if(t==NULL && i%2!=0)break;
            if(i%2 == 0 ){
                ListNode* first = h->next;
                ListNode* second = h->next->next;
                ListNode* third = h->next->next->next;
                ListNode* curr = h->next;
                first->next = t;
                while(second != t){
                    second ->next = first;
                    first = second;
                    second = third;
                    if(second == t)break;
                    third = third -> next;
                }
                h->next = first;
                h = curr;
            }
            else{
                while(h->next !=t)h = h->next;
            }
            size++;
        }
        return head;
    }
};