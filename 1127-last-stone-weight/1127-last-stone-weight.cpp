class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i = 0;i<stones.size();i++){
            pq.push(stones[i]);
        }
        while(pq.size()>1){
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            if(second<first)pq.push(first-second);
            if(pq.size()==0 || pq.size()==1)break;
        }
        if(pq.size()==1)return pq.top();
        return 0;

    }
};