class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
         vector<int>ans;
        for(int i=0;i<accounts.size();i++)
        {
            int sum=0;
             int max_sum=0;
            for(int j=0;j<accounts[i].size();j++)
            {
                
                sum=sum+accounts[i][j];
                max_sum=max(sum,max_sum);
                
            }
            ans.push_back(max_sum);
            
        }
        int p=*max_element(ans.begin(),ans.end());
        return  p;
        
    }
};