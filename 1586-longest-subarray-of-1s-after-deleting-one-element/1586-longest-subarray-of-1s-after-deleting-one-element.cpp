class Solution {
public:
bool check(vector<int>& nums, int mid){
        int n0=0;
        int sz=nums.size();
        for(int i=0;i<mid;i++){
            if(nums[i]==0)n0++;
        }
        if(n0<=1)return true;
        int i=1, j=mid;
        while(j<sz){
            if(nums[j]==0)n0++;
            if(nums[i-1]==0)n0--;
            if(n0<=1)return true;
            i++;j++;
        }
        return false;

}
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int l=1,h=n;
        int mid;
        int ans=0;
        while(l<=h){
            mid=(l+h)/2;
            if(check(nums,mid)){
                ans=mid;
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        return ans-1;
    }
};