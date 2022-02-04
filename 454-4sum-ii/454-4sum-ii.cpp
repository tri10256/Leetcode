class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        
        int count = 0;
        unordered_map<int,int>freq;
        
        for(auto &val1:nums1){
            for(auto &val2:nums2){
                freq[val1+val2]++;
            }
        }
        
        for(auto &val3:nums3){
            for(auto &val4:nums4){
                
                int curr = val3+val4;
                if(freq.count(0-curr))
                    count+=freq[0-curr];
            }
        }
        
        return count;
    }
};