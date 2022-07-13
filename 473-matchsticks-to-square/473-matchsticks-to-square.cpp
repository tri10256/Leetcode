class Solution {
    public:
    int possibleSide = 0;
    vector<int>sums{0,0,0,0};
    vector<int>nums;
    
    bool dfs(int i){
        
        if(i >= nums.size()){
          
            return (sums[0] == sums[1] && sums[1] == sums[2] && sums[2] == sums[3]);     
        }
        
        int element = nums[i];
       
        
        for(int j = 0;j<4;j++){
            
            if(sums[j] + element <= possibleSide){
                sums[j] += element;
                
                if(dfs(i+1)){
                    return true;
                }
                
                sums[j]-=element;
            }
        }
        
        
        return false;
    }
    
      bool makesquare(vector<int>matchsticks) {
        if(matchsticks.size() == 0)
            return false;
        
        int perimeter = 0;
        for(auto match:matchsticks){
            perimeter+=match;
            nums.push_back(match);
            
        }
          
       sort(nums.begin(),nums.end(),greater<int>());
        
        possibleSide = perimeter/4;
        
        
        if(possibleSide *4 == perimeter){
           return dfs(0);
           
        }
        
        
        return false;
    }
    
};
    
   
