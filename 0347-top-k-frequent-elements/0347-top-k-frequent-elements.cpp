class Solution {
public:
    struct descend{
        bool operator()(const pair<int,int>&a, const pair<int,int>&b) const{
            return a.second >= b.second;
        }
    };
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n  = nums.size();
        map<int,int>m;
        for(int i = 0 ; i<n ; i++){
            m[nums[i]]++;
        }
        set<pair<int,int>,descend>s;
        for(auto it = m.begin();it!=m.end();it++){
            s.insert({it->first,it->second});
        }
        int count = 0;
        vector<int>ans;
        for(auto & it:s){
            ans.push_back(it.first);
            count++;
            if(count==k)break;
        }
        return ans;
    }
};