class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>back(n);
        back[n-1] = n-1;
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                back[i] = n-1;
            }
            else back[i] = st.top()-1;
            st.push(i);
        }
        while(!st.empty())st.pop();
        vector<int>front(n);
        st.push(0);
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.top()]>=heights[i]){
                st.pop();
            }
            if(st.empty()){
                front[i] = 0;
            }
            else front[i] = st.top()+1;
            st.push(i);
        }
        int maxi = 0;
        for(int i = 0;i<n;i++){
            int ans = abs(back[i]-front[i]+1)*heights[i];
            maxi = max(maxi,ans);
        }
        return maxi;
    }
};