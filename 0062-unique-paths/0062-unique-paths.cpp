class Solution {
public:
    int path(int row,int column,vector<vector<int>>&dp){
        if(row == dp.size()-1 || column == dp[0].size()-1){
            return (row==dp.size()-1)?dp[row][column] = 1: dp[row][column]=1;
        }
        return (dp[row][column]!=-1)?dp[row][column]:dp[row][column] = path(row+1,column,dp)+path(row,column+1,dp);
    }
    int uniquePaths(int m, int n) {
        int row = 0;
        int column = 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(row,column,dp);
    }
};