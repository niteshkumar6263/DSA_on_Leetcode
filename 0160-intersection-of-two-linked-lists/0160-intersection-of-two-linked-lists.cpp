/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeofA=0;
        int sizeofB=0;
        ListNode* temp = headA;
        while(temp != NULL){
            sizeofA++;
            temp = temp -> next;
        }
        temp = headB;
        while(temp != NULL){
            sizeofB++;
            temp = temp -> next;
        }
        ListNode* tempheadA = headA;
        ListNode* tempheadB = headB;
        int d=0;
        if(sizeofA > sizeofB){
            d= abs(sizeofA -sizeofB);
            for(int i=1;i<=d;i++){
                tempheadA = tempheadA -> next;
            }
        }
        else if(sizeofA < sizeofB){
            d = abs(sizeofA - sizeofB);
            for(int i=1;i<=d;i++){
                tempheadB = tempheadB -> next;
            }
        }
        while(tempheadA != tempheadB && tempheadA != NULL){
            tempheadA = tempheadA -> next;
            tempheadB = tempheadB -> next;
        }
        return tempheadA;
    }
};