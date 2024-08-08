class Solution {
public:
void fin_d(vector<vector<int>>&ans,vector<int>&v,vector<int>s,int idx,int &k, int &n,int sum){
    int size=v.size();
    if(s.size()==k && sum==n){
        ans.push_back(s);
        return;
    }
    if(idx==9)return;
        if(sum+v[idx]<=n && s.size()<k){
            fin_d(ans,v,s,idx+1,k,n,sum);
            s.push_back(v[idx]);
            fin_d(ans,v,s,idx+1,k,n,sum+v[idx]);
        }
        else return;
}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>v(9);
        for(int i=0;i<9;i++){
            v[i]=i+1;
        }
        vector<int>s;
        int sum=0;
        fin_d(ans,v,s,0,k,n,sum);
        return ans;
        
    }
};