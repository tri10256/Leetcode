class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        
//          for(auto &x:mat){
//             for(auto &y:x){
//                 cout<<y<<" ";
//             }
//             cout<<endl;
//         }
      // cout<<endl;
        vector<vector<int>>ans;
        
        for(int k = 0;k<m;k++){
            
            int j = k;
            int i = 0;
            vector<int>temp;
            while(i<n && j<m){
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            ans.push_back(temp);
        }
        
        for(int k = 1;k<n;k++){
            
            int i = k;
            int j = 0;
            vector<int>temp;
            while(i<n && j<m){
                temp.push_back(mat[i][j]);
                i++;
                j++;
            }
            ans.push_back(temp);
        }
        
        for(int i  = 0;i<ans.size();i++){
            sort(ans[i].begin(),ans[i].end());
        }
         int s = 0;
         for(int k = 0;k<m;k++){
            
            int j = k;
            int i = 0;
            auto vec = ans[s];
             s++;
             int t = 0;
            while(i<n && j<m){
                mat[i][j] = vec[t];
               //cout<<vec[t]<<" ";
                i++;
                j++;
                t++;
            }
            // cout<<endl;
        }
        
          for(int k = 1;k<n;k++){
            
            int i = k;
            int j = 0;
            auto vec = ans[s];
              int t = 0;
              s++;
            while(i<n && j<m){
                mat[i][j] = vec[t];
              //  cout<<vec[t]<<" ";
                i++;
                j++;
                t++;
            }
            // cout<<endl;
        }
        // cout<<"temp"<<endl;
        // for(auto &x:ans){
        //     for(auto &y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return mat;
    }
};