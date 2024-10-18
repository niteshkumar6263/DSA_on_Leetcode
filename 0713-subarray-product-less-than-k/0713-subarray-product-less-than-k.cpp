class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int p=1;
        int count=0;
        for(int i=0;i<n;i++){
            p*=nums[i];
            while(p>=k && l<=i){
                p/=nums[l];
                l++;
            }
            count+=i-l+1;
        }
        return count;
    }
};