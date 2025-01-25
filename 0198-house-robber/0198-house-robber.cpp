class Solution {
public:
    int robit(int i,vector<int>&dp,vector<int>& nums){
        if(i>=dp.size()){
            return 0;
        }
        if(dp[i]!=-1)return dp[i];
        dp[i] = nums[i]+max(robit(i+2,dp,nums),robit(i+3,dp,nums));
        if(i+1>=dp.size())return dp[i];
        dp[i+1] = nums[i+1]+max(robit(i+3,dp,nums),robit(i+4,dp,nums));
        return max(dp[i],dp[i+1]);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n,-1);
        return robit(0,dp,nums);
    }
};