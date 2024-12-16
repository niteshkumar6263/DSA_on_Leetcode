class Solution {
public:
    unordered_map<char,int>m={{'(',-1},{'[',-2},{'{',-3},{')',1},{']',2},{'}',3}};
    bool isValid(string s) {
        int n = s.size();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(m[s[i]]<0)st.push(s[i]);
            else{
                if(!st.empty() && m[st.top()]+m[s[i]]==0){
                    st.pop();
                }
                else return false;
            }
        }
        if(st.empty()) return true;
        return false;
    }
};