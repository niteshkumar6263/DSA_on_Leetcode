class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int l=0,r=0;
        int maxi=0;
        int count=0;
        vector<int>v(150);
        while(r<n){
            if(v[(int)s[r]]==0) {
                v[(int)s[r]]++;
                
            }
            else{
                count=r-l;
                maxi=max(maxi,count);
                for(int i=l;i<r;i++){
                    if(s[i]==s[r]){
                        l=i+1;
                        break;
                    }
                }
            }
            r++;
        }
        count=r-l;
        maxi=max(maxi,count);
        return maxi;
    }
};