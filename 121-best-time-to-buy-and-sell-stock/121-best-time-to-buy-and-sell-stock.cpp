class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxm=0;
        int max_so_far=0;
        for(int i=1;i<prices.size(); i++)
        {
            maxm=max(0,maxm+(prices[i]-prices[i-1]));
            max_so_far=max(maxm,max_so_far);
        }
        return max_so_far;
        
    }
};