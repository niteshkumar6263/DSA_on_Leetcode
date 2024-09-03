class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int j=n-1;
        for(int i=0;i<=j;){
            if(nums[i]-1==i)i++;
            else if(nums[nums[i]-1]!=nums[i]){
                swap(nums[nums[i]-1],nums[i]);
            }
            else {
                swap(nums[i],nums[j]);
                j--;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]-1!=i)return nums[i];
        }
        return n;
    }
};