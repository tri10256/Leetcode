class Solution {
public:
    vector<vector<int>>vec;
    void nocomb(vector<int>veci,int sum,int j,int target,vector<int>freq)
    { 
           if(sum>target){
                return;
           }
           if(sum == target){
               vec.push_back(veci);
               return;
           }
        
            for(auto i = j;i<freq.size();i++)
            {   if(freq[i] == 0)
                continue;
                sum+=i;
                freq[i]--;
                veci.push_back(i);
                nocomb(veci,sum,i,target,freq);
                veci.pop_back();
                sum -=i;
            }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int>veci;
        int n = candidates.size();
       // int maxi = *max_element(candidates.begin(),candidates.end());
        vector<int>freq(102,0);
        for(auto num:candidates)
            freq[num]++;
        
        nocomb(veci,0,0,target,freq);
        return vec;
    }
};