class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        priority_queue<int>pq;
        stack<int>st;
        int n = nums.size();
        for(int i = nums.size()-1;i>=0;i--)
            st.push(nums[i]);
        
        if(k %2 != 0 && nums.size() == 1)
            return -1;
        if(k > n ){
            int maxi = *max_element(nums.begin(),nums.end());
            pq.push(maxi);
            k = k-1;
        }
        
        if(k!=n)
        k = k%nums.size();
        
        int steps = k-1;
        
        if(steps == 0){
            while(k--){
                st.pop();
            }
            
             if(st.empty())
            return -1;
        }
       
        while(steps > 0){
            pq.push(st.top());
            st.pop();
            steps--;
        }
        
        if(pq.size()>0){
        st.pop();
        if(st.empty())
            st.push(pq.top());
        else if(pq.top() > st.top())
        st.push(pq.top());
        }
        
        return st.top();
    }
};