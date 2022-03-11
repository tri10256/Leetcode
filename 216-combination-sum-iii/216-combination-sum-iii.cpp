class Solution {
public:
    vector<vector<int>>vec;
    void nocomb(vector<int>veci,int sum,int j,int target,int k)
    { 
           if(sum>target){
                return;
           }
           if(sum == target){
               if(veci.size()==k)
               vec.push_back(veci);
               return;
           }
        
            for(auto i = j;i<10;i++)
            {  
                sum+=i;
                veci.push_back(i);
                nocomb(veci,sum,i+1,target,k);
                veci.pop_back();
                sum -=i;
            }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>veci;
        nocomb(veci,0,1,n,k);
        return vec;
    }
};