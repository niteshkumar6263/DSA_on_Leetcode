class Solution {
public:
bool check(vector<int>& nums, int k, int mid){
        int n=nums.size();
        int presum=0; int i,j;
        int count=0;
            for(int i=0;i<mid;i++){
                if(nums[i]==0)count++;
            }
            if(count<=k){
                return true;
            }
            i=1;j=mid;
            while(j<n){
                if(nums[j]==0)count++;
                if(nums[i-1]==0)count--;
                if(count<=k){
                return true;
                }
                i++;j++;
            }
            return false;
}
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int l=1;int h=n;
        int mid;
        int realsize=0;
        while(l<=h){
            mid=(l+h)/2;
            if(check(nums,k,mid)){
                realsize=mid;
                l=mid+1;
            }
            else {
                h=mid-1;
            }
        }
        return realsize;
    }
};