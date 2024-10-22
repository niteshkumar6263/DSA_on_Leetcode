class Solution {
public:
int countsubarray(vector<int>& nums, int goal){
        int n=nums.size();
        if(goal<0)return 0;
        int l=0;
        int r=0;
        int sum=0;
        int count=0;
        while(r<n){
            sum+=nums[r];
            while(sum>goal){
                sum-=nums[l];
                l++;
            }
            if(sum<=goal){
                count+=r-l+1;
            }
            r++;
        }
        return count;
}
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans1=countsubarray(nums,goal);
        int ans2=countsubarray(nums,goal-1);

        return {ans1-ans2};
    }
};