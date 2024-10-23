class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        int r=0;
        int l=0;
        int count=0;
        vector<int>v(3);
        while(r<n){
            v[s[r]-97]++;
            if(v[0]!=0 && v[1]!=0 && v[2]!=0){
                count+=n-r;
            }
            while(v[0]!=0 && v[1]!=0 && v[2]!=0 && l<=r){
                v[s[l]-97]--;
                if(v[0]!=0 && v[1]!=0 && v[2]!=0)count+=n-r;
                l++;
            }
            r++;
        }
        return count;
    }
};