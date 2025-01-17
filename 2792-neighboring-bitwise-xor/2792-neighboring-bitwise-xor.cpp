class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int n = derived.size();
        if(n==1){
            if(derived[0]==0)return true;
            return false;
        }
        vector<int>a = derived;
        vector<int>b = derived;
        a.push_back(1);
        b.push_back(0);
        for(int i = n-1;i>=0;i--){
            a[i] = a[i]^a[i+1];
            b[i] = b[i]^b[i+1];
        }
        if(a[0]==a[n] || b[0]==b[n])return true;
        return false;
    }
};