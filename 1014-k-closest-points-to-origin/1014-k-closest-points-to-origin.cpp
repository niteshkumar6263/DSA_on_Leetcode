class Solution {
public:
    typedef long long ll;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>>pq;
        for(int i = 0;i<points.size();i++){
            double distance = sqrt(pow(points[i][0],2) + pow(points[i][1],2));
            pq.push({distance,i});
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({points[pq.top().second][0],points[pq.top().second][1]});
            pq.pop();
        }
        return ans;
    }
};