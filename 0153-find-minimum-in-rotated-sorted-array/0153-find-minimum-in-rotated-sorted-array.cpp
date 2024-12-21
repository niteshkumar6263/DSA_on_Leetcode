class Solution {
public:
    int findMin(vector<int>& nums) {
        int k=0;
        int n = nums.size();
        for(int i = n-1;i>=1;i/=2){
            while(i+k<n && nums[i+k]>nums[0] && nums[i+k-1]<nums[i+k])k+=i;
        }
        if(k+1==n)return nums[0];
        return nums[k+1];
    }
};