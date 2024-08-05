class Solution {
public:
    bool check(vector<int>& bloomDay, int m, int k,int mid){
        int n=bloomDay.size();
        vector<int>v(n);
        for(int i=0;i<n;i++){
            if(bloomDay[i]<=mid)v[i]=1;
        }
        int count=0;
        if(v[0]==1)count++;
        if(count==k){
            m-=1;
            count=0;
        }
        for(int i=1;i<n;i++){
            if(v[i]==1 && v[i-1]==0)count=1;
            else if(v[i]==0 && v[i-1]==1)count=0;
            else if(v[i]==v[i-1] && v[i]==1)count++;
            if(count==k && m>0){
                count=0;
                m--;
            }
            if(m==0)return true;
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int>v=bloomDay;
        int n=bloomDay.size();
        if(m>(n/k))return -1;
        sort(v.begin(),v.end());
        vector<int>x;
        x.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(v[i]!=x[x.size()-1])x.push_back(v[i]);
        }
        int l=0;int h=x.size()-1;
        int mid;
        int ans=-1;
        while(l<=h){
            mid=(l+h)/2;
            if(check(bloomDay,m,k,x[mid])){
                ans=x[mid];
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};