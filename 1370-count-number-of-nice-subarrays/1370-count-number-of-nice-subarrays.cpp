class Solution {
public:
int countsub(vector<int>& nums, int k){
    int count=0;
    int n=nums.size();
    int l=0,r=0;
    int sum=0;
    while(r<n){
        sum+=nums[r]%2;
        while(sum>k){
            sum-=(nums[l]%2);
            l++;
        }
        if(sum<=k){
            count+=r-l+1;
        }
        r++;
    }
    return count;
}
    int numberOfSubarrays(vector<int>& nums, int k) {
        return countsub(nums,k)-countsub(nums,k-1);
    }
};