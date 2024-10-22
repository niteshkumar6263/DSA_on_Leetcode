class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        int count=0;
        map<int,int>m;
        m[0]++;
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(m.find(sum-goal)!=m.end()){
                count+=m[sum-goal];
            }
            m[sum]++;
        }
        return count;
    }
};