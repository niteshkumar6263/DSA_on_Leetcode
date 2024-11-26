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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        long long size = lists.size();
        if(size==0)return NULL;
        long long i = 0;
        ListNode* start = NULL;
        for(;i<size;i++){
            if(lists[i]!=NULL){
                start = lists[i];
                i++;
                break;
            }
        }
        if(start == NULL)return NULL;
        ListNode* firstnode;
        ListNode* secondnode;
        ListNode* current;
        while(i<size){
            if(lists[i]!=NULL){
                firstnode = start;
                secondnode = lists[i];
                if(firstnode->val <= secondnode->val){
                    start = firstnode;
                    firstnode = firstnode->next;
                }
                else{
                    start = secondnode;
                    secondnode = secondnode->next;
                }
                current = start;
                while(firstnode && secondnode){
                    if(firstnode->val <= secondnode->val){
                        current->next = firstnode;
                        firstnode = firstnode->next;
                    }
                    else{
                        current->next = secondnode;
                        secondnode  = secondnode->next;
                    }
                    current = current->next;
                }
                if(firstnode!=NULL){
                    current->next = firstnode;
                }
                else{
                    current->next = secondnode;
                }
            }
            i++;
        }
        return start;
    }
};