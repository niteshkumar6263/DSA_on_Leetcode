class Solution {
public:
    int climb(int i,vector<int>&dp,vector<int>& cost){
        if(i>=cost.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int first = 0;
        int second = 0;
        if(i<cost.size())first = cost[i];
        if((i+1)<cost.size())second = cost[i+1];
        return dp[i] = min(first+climb(i+1,dp,cost),second+climb(i+2,dp,cost));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n,-1);
        return climb(0,dp,cost);
    }
};