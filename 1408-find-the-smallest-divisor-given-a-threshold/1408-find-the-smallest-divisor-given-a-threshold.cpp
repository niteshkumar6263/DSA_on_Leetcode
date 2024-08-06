class Solution {
public:
    bool check(vector<int>& nums, int &threshold,int mid){
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]%mid!=0)
            sum+=(nums[i]/mid)+1;
            else sum+=nums[i]/mid;
        }
        cout<<endl;
        if(sum<=threshold)return true;
        return false;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxi=0;
        int l=1;
        for(int i=0;i<n;i++){
            if(maxi<nums[i])maxi=nums[i];
        }
        int h=maxi;
        int mid;
        int ans=-1;
        while(l<=h){
            mid=(l+h)/2;
            if(check(nums,threshold,mid)){
                ans=mid;
                h=mid-1;
            }
            else l=mid+1;
        }
        return ans;
    }

};