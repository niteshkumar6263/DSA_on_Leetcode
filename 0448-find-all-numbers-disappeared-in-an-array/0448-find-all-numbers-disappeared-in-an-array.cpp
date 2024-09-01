class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n+1);
        for(int i=0;i<n;i++){
            if(ans[nums[i]]==0){
                ans[nums[i]]++;
            }
        }
        vector<int>v;
        for(int j=1;j<n+1;j++){
            if(ans[j]==0){
                v.push_back(j);
            }
        }
        return v;

    }
};