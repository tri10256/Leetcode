class Solution {
public:
    vector<int> getRow(int n) {
        vector<vector<int>>ans;
        
        vector<int>vec;
        vec.push_back(1);
        ans.push_back(vec);
        
        vec.clear();
        
        vec.push_back(1);
        vec.push_back(1);
        ans.push_back(vec);
        
        for(int i=2;i<=n;i++)
        {
            
           vector<int>newvec=ans[i-1];
            vector<int>nans;
            nans.push_back(1);
            
            for(int j=0;j<newvec.size()-1;j++)
            {

                nans.push_back(newvec[j]+newvec[j+1]);
            }
            nans.push_back(1);
            ans.push_back(nans);
            
    
        }
    
        return ans[n];
        
    }
};