class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int sum=0;
        int maxi=0;
        for(int i=0;i<k;i++){
            sum+=cardPoints[i];
        }
        maxi=max(sum,maxi);
        int l=k-1;int r=n-1;
        while(l>=0){
            sum-=cardPoints[l];
            sum+=cardPoints[r];
            maxi=max(maxi,sum);
            l--;r--;
        }
        return maxi;
    }
};