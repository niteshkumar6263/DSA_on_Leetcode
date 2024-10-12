class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n=nums.size();
        int sub=1<<n;
        vector<vector<int>>ans;
        vector<int>v;
        for(int i=0;i<sub;i++){
            for(int j=0;j<n;j++){
                if((i>>j)&1)v.push_back(nums[j]);
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};