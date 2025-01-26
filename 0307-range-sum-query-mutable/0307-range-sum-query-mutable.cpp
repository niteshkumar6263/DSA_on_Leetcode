class NumArray {
public:
    vector<int>st;
    vector<int>nums;
    int n;
    void buildTree(vector<int>&v,int i,int low, int high){
        if(low == high){
            st[i] = v[low];
            return;
        }
        int mid = (low+high)/2;
        buildTree(v,2*i+1,low,mid);
        buildTree(v,2*i+2,mid+1,high);
        st[i] = st[2*i+1]+st[2*i+2];
    }
    int getSum(int i, int low, int high, int l , int r){
        if(high<l || low>r)return 0;
        if(low>=l && high<=r) return st[i];
        int mid = (low+high)/2;
        int left = getSum(2*i+1,low,mid,l,r);
        int right = getSum(2*i+2,mid+1,high,l,r);
        return left+right;
    }
    void updatechange(int i, int low, int high,int index,int val){
        int mid = (low+high)/2;
        if(low == high){
            st[i] += val;
            return;
        }
        st[i]+=val;
        if(index<=mid)updatechange(2*i+1,low,mid,index,val);
        else updatechange(2*i+2,mid+1,high,index,val);
    }
    NumArray(vector<int>& nums) {
        this->nums = nums;
        n = nums.size();
        st.resize(4*n);
        buildTree(nums,0,0,n-1);
    }
    void update(int index, int val) {
        int dif = val - nums[index];
        nums[index] = val;
        updatechange(0,0,n-1,index,dif);
    }

    int sumRange(int left, int right) {
        return getSum(0,0,n-1,left,right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */