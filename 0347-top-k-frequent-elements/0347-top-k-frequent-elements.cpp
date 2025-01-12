class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n  = nums.size();
        map<int,int>m;
        for(int i = 0 ; i<n ; i++){
            m[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto it = m.begin();it!=m.end();it++){
            v.push_back({it->second,it->first});
        }
        m.clear();
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        for(int i = 0;i<v.size();i++){
            p.push(v[i]);
            if(p.size()>k)p.pop();
        }
        vector<int>ans;
        while(!p.empty()){
            ans.push_back(p.top().second);
            p.pop();
        }
        return ans;
    }
};