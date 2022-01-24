class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        
        queue<int>q{{1,2,3,4,5,6,7,8,9}};
        vector<int>ans;
        
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            
            if(curr<=high && curr>=low)
                ans.push_back(curr);
            
            int rem = curr%10;
            int next = curr*10 + (rem+1);
            
            if(rem<9)
                q.push(next);
        }
        
        return ans;
    }
};