class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
 
       priority_queue<vector<int>>pq;
        
        for(auto vec:points){
            int d1 = abs(vec[0]*vec[0] + vec[1]*vec[1]);
            vector<int>temp{d1,vec[0],vec[1]};
            pq.push(temp);
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            auto vec = pq.top();
            ans.push_back({vec[1],vec[2]});
            pq.pop();
        }
       
    
        return ans;
    }
};