class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        
        int low = -1;
        int high  = -1;
        
        vector<vector<int>>ans;
        for(auto &interval:intervals){
            
            int first = interval[0];
            int second = interval[1];
            
            if(low == -1){
                low = first;
            }
            if(high == -1){
                high = second;
            }
            
            if(first>high){
                ans.push_back({low,high});
                low = first;
                high = second;
            }else {
                low = min(low,first);
                high = max(high,second);
            }
                
        }
        ans.push_back({low,high});
        
        return ans;
    }
};