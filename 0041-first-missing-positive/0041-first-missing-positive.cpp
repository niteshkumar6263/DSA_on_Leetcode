class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        set<int>v;
        for(int i=0;i<n;i++){
            if(nums[i]>0)v.insert(nums[i]);
        }
        vector<int>s;
        for(int i:v){
            s.push_back(i);
        }
        sort(s.begin(),s.end());
        int l=v.size();
        int k=1;
        for(int i=0;i<l;i++){
            if(s[i]==k)k++;
            else return k;
        }
        return k;
    }
};