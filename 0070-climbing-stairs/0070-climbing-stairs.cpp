class Solution {
public:
    int climb(int i,vector<int>&dp){
        if(i>=dp.size()-1)return (i==dp.size()-1)? 1: 0;
        return (dp[i]!=-1) ?dp[i]: dp[i] = climb(i+1,dp) + climb(i+2,dp); 
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return climb(0,dp);

    }
};