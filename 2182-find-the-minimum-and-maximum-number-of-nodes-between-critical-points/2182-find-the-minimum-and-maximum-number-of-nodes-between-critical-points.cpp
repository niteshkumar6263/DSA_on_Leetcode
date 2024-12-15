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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(head ->next->next ==NULL){
            vector<int>v(2,-1);
            return v;
        }
        ListNode* temp = head;
        int a,b,c;
        int fidx = -1,sidx = -1;
        int f = -1 , s=-1;
        int pos = 1;
        int mini = INT_MAX;
        while(temp->next->next!=NULL){
            a = temp->val;
            b = temp->next->val;
            c = temp->next->next->val;
            if(a<b && c<b || b<a && b<c){
                (fidx == -1)?fidx = pos:sidx = pos;
                f=s;
                s = pos;
                if(f!=-1){
                    mini = min(mini,s-f);
                }
            }
            temp = temp->next;
            pos++;
        }
        int maxd = sidx-fidx;
        if(sidx==-1)return {-1,-1};
        return {mini,maxd};
    }
};