class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        sort(nums.begin(),nums.end());
        int sum=0;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            sum+=nums[i];
            v[i]=sum;
        }
        vector<int>ans(m);
        
        for(int i=0;i<m;i++){
            int l=0, h=n-1;
            int mid;
            while(l<=h){
                mid=(l+h)/2;
                if(v[mid]<=queries[i]){
                    ans[i]=mid+1;
                    l=mid+1;
                }
                else{
                    h=mid-1;
                }
            }
        }
        return ans;
    }
};