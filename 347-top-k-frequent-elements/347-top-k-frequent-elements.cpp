class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        unordered_map<int,int>freq;
        
        for(auto num:nums){
            freq[num]++;
        }
        
        for(auto it:freq){
            int key = it.first;
            int val = it.second;
            
            pq.push({val,key});
        }
        
        vector<int>ans;
        
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};