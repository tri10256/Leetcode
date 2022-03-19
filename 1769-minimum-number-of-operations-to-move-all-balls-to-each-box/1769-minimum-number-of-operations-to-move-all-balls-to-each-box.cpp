class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n = boxes.size();
        vector<int>ans(n,0);
        
        
        for(int i = 0;i<boxes.size();i++){
            int steps = 0;
            for(int j = 0;j<boxes.size();j++){
                if(i != j && boxes[j] == '1'){
                    steps+=abs(i-j);
                }
            }
            
            ans[i] = steps;
        }
        
        return ans;
    }
};