class Solution {
public:
    vector<vector<int>>vec;
    void nocomb(vector<int>&candidates,int target,int j,vector<int>veci,int sum)
    {
           if(sum>target){
                return;
           }
           if(sum == target)
               vec.push_back(veci);
        
            for(int i=j;i<candidates.size();i++)
            {
                sum+=candidates[i];
                veci.push_back(candidates[i]);
                nocomb(candidates,target,i,veci,sum);
                veci.pop_back();
                sum -=candidates[i];
            }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>veci;
        nocomb(candidates,target,0,veci,0);
        return vec;   
    }
};