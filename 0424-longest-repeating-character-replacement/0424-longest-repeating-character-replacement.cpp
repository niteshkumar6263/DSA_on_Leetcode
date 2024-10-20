class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxchar=0;
        int maxi=0;
        int l=0,r=0;
        vector<int>v(26);

            while(r<n){
                v[s[r]-65]++;
                maxchar=max(maxchar,v[s[r]-65]);
                if(r-l+1-maxchar>k){
                    v[s[l]-65]--;
                    maxi=max(maxi,r-l);
                    l++;
                }
                r++;
            }
            maxi=max(r-l,maxi);
            return maxi;   
    }
};