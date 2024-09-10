class Solution {
public:
    int bestClosingTime(string customers) {
        int n=customers.size();
        vector<int>l(n);
        vector<int>r(n);
        int count=0;
        for(int i=0;i<n;i++){
            if(customers[i]=='N')count++;
            l[i]=count;
        }
        count=0;
        for(int i=n-1;i>=0;i--){
            if(customers[i]=='N')count++;
            r[i]=count;
        }
        vector<int>ans(n+1);
        for(int i=0;i<n;i++){
            if(customers[i]=='N'){
               ans[i]=n-i-1-r[i]+l[i]; 
            }
            else ans[i]=n-i-r[i]+l[i];
        }
        ans[n]=l[n-1];
        int min=0;
        for(int i=0;i<n+1;i++){
            if(ans[i]<ans[min])min=i;
        }
        // if(customers[min]=='N')return min;
        // else return min+1;
        return min;
    }
};