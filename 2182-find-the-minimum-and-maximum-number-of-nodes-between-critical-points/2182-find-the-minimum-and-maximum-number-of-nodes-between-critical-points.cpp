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
        vector<int>critical;
        int pos = 1;
        while(temp->next->next!=NULL){
            a = temp->val;
            b = temp->next->val;
            c = temp->next->next->val;
            if(a<b && c<b || b<a && b<c){
                critical.push_back(pos);
            }
            temp = temp->next;
            pos++;
        }
        int n = critical.size();
        if(n==0 || n==1){
            vector<int>v(2,-1);
            return v;
        }
        sort(critical.begin(),critical.end());
        vector<int>v;
        int mini = INT_MAX;
        for(int i=1;i<n;i++){
            mini = min(mini,critical[i]-critical[i-1]);
        }
        v.push_back(mini);
        v.push_back(critical[n-1]-critical[0]);
        return v;
    }
};