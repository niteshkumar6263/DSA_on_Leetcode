class Solution {
    using ll=long long;
public:
    bool f(vector<int>&nums, ll mid){
        ll c=0;
        for(auto i:nums){
            if(i<=mid)c++;
        }
        return c>mid;
    }
    int findDuplicate(vector<int>& nums) {
        ll n=nums.size()-1;
        ll low=1,high=n;
        while(low<=high){
            ll mid=(low+high)/2;
            if(f(nums,mid)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};