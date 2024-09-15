class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n=customers.size();
        int presum1=0;
        int grusum=0;
        int maxid=0;
        for(int i=0;i<minutes;i++){
            if(grumpy[i]==1){
                presum1+=customers[i];    
            }
            grusum+=grumpy[i];
        }
        int presummax=presum1;
        int grusummax=grusum;
        int i=1;int j=minutes;
        while(j<n){
            if(grumpy[j]==1){
                presum1=presum1+customers[j];
            }
            if(grumpy[i-1]==1){
                presum1=presum1-customers[i-1];
            }
            grusum=grusum+grumpy[j]-grumpy[i-1];
            if(grusum>=grusummax && presum1>presummax){
                    maxid=i;
                    presummax=presum1;
            }
            // else if(grusum>grusummax){
            //     maxid=i;
            //     grusummax=grusum;
            // }
            i++;j++;
        }
        // cout<<maxid<<endl;
        int ans =0;
        for (int i=0;i<n;i++){
            if(i>=maxid && i<minutes+maxid)ans+=customers[i];
            else if(grumpy[i]==0)ans+=customers[i];
        }
        return ans;
    }
};