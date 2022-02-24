class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
 
       priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        
        for(auto vec:points){
            int d1 = abs(vec[0]*vec[0] + vec[1]*vec[1]);
            vector<int>temp{d1,vec[0],vec[1]};
            pq.push(temp);
        }
        vector<vector<int>>ans;
        while(k>0){
            auto vec = pq.top();
            pq.pop();
            ans.push_back({vec[1],vec[2]});
            k--;
        }
       
        
        return ans;
    }
};