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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* head2;
        ListNode* tail;
        int size = 0;
        while(temp!=NULL){
            if(temp->next == NULL)tail = temp;
            temp = temp->next;
            size++;
        }
        if(size==0)return NULL;
        k = k%size;
        if(k==0)return head;
        temp = head;
        for(int i=1;i<size-k;i++){
            temp = temp->next;
        }
        head2 = temp->next;
        temp->next = NULL;
        tail->next = head;
        return head2;
    }
};