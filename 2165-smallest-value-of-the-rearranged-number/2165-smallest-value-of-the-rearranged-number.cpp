class Solution {
public:
    
    long long positive(long long &num){
        priority_queue<int ,vector<int>,greater<int>>pq;
        while(num!=0){
            
            int rem = num%10;
           // cout<<rem<<" ";
            pq.push(rem);
            num/=10;
        }
        long long ans=0;
        vector<int>buffer;
        while(!pq.empty()){
            long long int val = pq.top();
            pq.pop();
            if(val == 0){
                buffer.push_back(val);
                continue;
            }else{
                int sz = buffer.size();
                if(sz!=0){
                    while(sz){
                        val*=10;
                        sz--;
                    }
                    buffer.clear();
                    ans = val;
                }else{
                    ans*=10;
                    ans += val;
                }
            }
        }
        
        return ans;
    }
    long long negative(long long &num){
          priority_queue<int>pq;
        while(num!=0){
            
            int rem = num%10;
            pq.push(rem);
            num/=10;
        }
        long long ans=0;
       
        while(!pq.empty()){
            int val = pq.top();
           // cout<<val;
            pq.pop();
            ans*=10;
            ans+=val;
        }
        
    
        return (-1*ans); 
    }
    long long smallestNumber(long long num) {
       if(num<0){
           num*=-1;
          return negative(num);  
       }
        
      return positive(num); 
    }
};