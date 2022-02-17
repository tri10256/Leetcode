class Solution {
public:
    
    void nocomb(vector<int>&candidates,int target,vector<vector<int>>&vec,int j,vector<int>veci,int sum)
    {
           if(sum>target)
            {
                return;
            }
            if(target==sum)
                vec.push_back(veci);
        for(int i=j;i<candidates.size();i++)
        { sum+=candidates[i];
         veci.push_back(candidates[i]);
         nocomb(candidates,target,vec,i,veci,sum);
         target+=candidates[i];
         veci.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
         vector<vector<int>>vec;
        vector<int>veci;
         nocomb(candidates,target,vec,0,veci,0);
        return vec;
        
        
    }
};