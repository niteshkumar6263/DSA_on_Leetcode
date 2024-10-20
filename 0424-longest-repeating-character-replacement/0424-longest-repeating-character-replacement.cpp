class Solution {
public:
     int characterReplacement(string s, int k) {
        int e=2;
            int maxi=0;
            int l,r;
        while(e--){
            int n=s.size();
             l=0,r=0;
            int firstchange=0;
            int maxchar=0;
            vector<int>v(26);
            while(r<n){
                v[(int)s[r]-65]++;
                maxchar=max(maxchar,v[s[r]-65]);
                // if(r-l+1-maxchar==1 && s[r]!=s[firstchange])firstchange=r;
                for(int i=l+1;i<n;i++){
                if(s[i]!=s[l]){
                    firstchange=i;
                    break;
                }
                }
                // cout<<s[firstchange]<<" "<<firstchange<<" "<<r<<" "<<l<<endl;
                if(r-l+1-maxchar>k){
                    maxi=max(maxi,r-l);
                    l=firstchange;
                    maxchar=0;
                    r=l-1;
                    vector<int>y(26);
                    v=y;
                    y.clear();
                    // cout<<"helo "<<l<<" "<<r<<endl;
                }
                r++;
            }
            reverse(s.begin(),s.end());
        }
        maxi=max(maxi,r-l);
        return maxi;
    }
};