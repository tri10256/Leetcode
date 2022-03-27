class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int,int>>ans;
        vector<int>finalans;
        
        for(int i =0;i<mat.size();i++){
            int count = 0;
            for(int j = 0;j<mat[i].size();j++){
                if(mat[i][j] == 1)
                    count++;
            }
            ans.push_back({count,i});
        }
        
        sort(ans.begin(),ans.end());
        
        int i = 0;
        while(k--){
            finalans.push_back(ans[i].second);
            i++;
        }
        
        return finalans;
    }
};