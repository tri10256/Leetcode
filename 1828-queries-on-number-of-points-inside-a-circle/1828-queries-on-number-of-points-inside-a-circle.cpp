class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        
        vector<int>ans;
        for(auto query:queries){
            int x = query[0];
            int y = query[1];
            int r = query[2];
            int count = 0;
            for(auto point:points){
                int x1 = point[0];
                int y1 = point[1];
                
                if((x1-x)*(x1-x) + (y1 - y)*(y1-y) <= r*r){
                   // cout<<x1<<" "<<y1<<endl;
                    count++; 
                }
            }
            ans.push_back(count);
        }
        
        return ans;
    }
};