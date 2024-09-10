class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        int nz=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)nz++;
        }
        vector<int>v(n);
        if(nz>1)return v;
        else if(nz==1){
            int idx=-1;
            int pr=1;
            for(int i=0;i<n;i++){
                if(nums[i]==0){
                    idx=i;
                    continue;
                }
                pr*=nums[i];
            }
            v[idx]=pr;
            return v;
        }
        else{
            int pd=1;
            for(int i=0;i<n;i++){
                pd*=nums[i];
            }
            for(int i=0;i<n;i++){
                v[i]=(pd/nums[i]);
            }
            return v;
        }
    }
};