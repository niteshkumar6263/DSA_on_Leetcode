class Solution {
public:
   int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0,r=0,m=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2!=0){
                l=i;
                break;
            }
        }
        r=l;
        int countodd=0;
        int count=0;
        while(r<n){
            if(nums[r]%2!=0){
                countodd++;
            }
            if(countodd==k){
                count+=l-m+1;
            }
            else if(countodd>k){
                m=l+1;
                countodd--;
                for(int i=m;i<=r;i++){
                    if(nums[i]%2!=0){
                        l=i;
                        break;
                    }
                }
                count+=l-m+1;
            }
            r++;
        }
        return count;
    }
};