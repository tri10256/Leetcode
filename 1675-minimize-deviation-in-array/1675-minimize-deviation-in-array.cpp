class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int ans = INT_MAX;
        int mini = INT_MAX;
        
        priority_queue<int>pq;
        
        for(auto &num:nums){
            if(num%2==1)
                num*=2;
            pq.push(num);
            mini = min(mini,num);
        }
        
        while(pq.top()%2 == 0){
            ans = min(ans,pq.top() - mini);
            int val = pq.top();
            pq.pop();
            val/=2;
            mini = min(mini,val);
            pq.push(val);
        }
        
        return min(ans,(pq.top() - mini));
    }
};