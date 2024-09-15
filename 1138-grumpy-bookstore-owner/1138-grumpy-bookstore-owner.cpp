class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int preloss=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1)preloss+=customers[i];
        }
        int maxloss=preloss;
        int maxId=0;
        int i=1;
        int j=minutes;
        while(j<n){
            int currloss=preloss;
            if(grumpy[j]==1)currloss+=customers[j];
            if(grumpy[i-1]==1)currloss-=customers[i-1];
            if(currloss>maxloss){
                maxloss=currloss;
                maxId=i;
            }
            preloss=currloss;
            i++;j++;
        }
        long long ans=0;
        for(int i=0;i<n;i++){
            if(i>=maxId && i<minutes+maxId)ans+=customers[i];
            else if(grumpy[i]==0)ans+=customers[i];
        }
        return ans;

    }
};