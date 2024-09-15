class Solution {
public:
bool check(int mid, int target, vector<int>& nums){
        int n=nums.size();
        int presum=0; int i,j;
            for(int i=0;i<mid;i++){
                presum+=nums[i];
            }
            if(presum>=target){
                return true;
            }
            i=1;j=mid;
            while(j<n){
                presum=presum+nums[j]-nums[i-1];
                if(presum>=target){
                    return true;
                }
                i++;j++;
            }
            return false;
}
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=1;int h=n;
        int realsize=0;
        int mid;
        while(l<=h){
            mid=(l+h)/2;
            if(check(mid,target,nums)){
                realsize=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return realsize;
    }
};