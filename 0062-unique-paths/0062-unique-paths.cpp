class Solution {
public:
    int path(int row,int column, int &m,int & n,vector<vector<int>>&dp){
        if(row == m-1 || column == n-1){
            return (row==m-1)?dp[row][column] = 1: dp[row][column]=1;
        }
        return (dp[row][column]!=-1)?dp[row][column]:dp[row][column] = path(row+1,column,m,n,dp)+path(row,column+1,m,n,dp);
    }
    int uniquePaths(int m, int n) {
        int row = 0;
        int column = 0;
        vector<vector<int>>dp(m,vector<int>(n,-1));
        return path(row,column,m,n,dp);
    }
};