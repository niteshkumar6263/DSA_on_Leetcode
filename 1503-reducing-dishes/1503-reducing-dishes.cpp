class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int sum=0;
        int idx=n;
        for(int i=n-1;i>=0;i--){
            if(sum+satisfaction[i]>=0){
                sum+=satisfaction[i];
                idx=i;
            }
            else break;
        }
        int count=1;
        sum=0;
        for(int i=idx;i<n;i++){
            sum+=count*satisfaction[i];
            count++;
        }
        return sum;
        
    }
};