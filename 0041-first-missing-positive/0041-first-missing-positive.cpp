class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;){
            if(nums[i]==i+1 || nums[i]>n || nums[i]<1 )i++;
            else if(nums[nums[i]-1]==nums[i])i++;
            else{
                swap(nums[nums[i]-1], nums[i]);
            }
        }
        int i=0;
        for(;i<n;i++){
            if(nums[i]==i+1)continue;
            else break;
        }
        return i+1;
    }
};