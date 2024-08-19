class Solution {
public:
long long power(long long a,long long b){
    if(b==0)return 1;
    if(b==1)return a;
    long long ans;
    ans=power(a,b/2);
    if(ans>=(1e9+7)){
        ans=ans%(1000000007);
    }
    if(b%2==0) {
        return ans*ans;
        }
    else {
        return a*ans*ans;
        }
}
    int countGoodNumbers(long long n) {
        long long a1=power(5,n-n/2);
        if(a1>=(1e9+7)){
            a1=a1%(1000000007);
        }
        long long a2=power(4,n/2);
        if(a2>=(1e9+7)){
            a2=a2%(1000000007);
        }
        long long ans=a1*a2;
        if(ans>=(1e9+7)){
            ans=ans%(1000000007);
        }
        return (int)ans;
    }
};