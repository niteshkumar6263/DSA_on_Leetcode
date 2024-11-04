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
    bool hasCycle(ListNode *head) {
        int t = 1e4+1;
        ListNode* temp = head;
        while(t--){
            if(temp==NULL)return false;
            temp = temp -> next;
        }
        return true;

    }
};