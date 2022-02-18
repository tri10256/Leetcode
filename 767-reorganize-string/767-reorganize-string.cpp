class Solution {
public:
    string reorganizeString(string s) {
        
        int freq[26] = {};
        
        for(auto &it:s){
            freq[it-'a']++;
        }
        
        priority_queue<pair<int,int>>pq;
        
        for(int i = 0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i],i});
            }
        }
        
        string ans = "";
        while(pq.size()>1){
            pair<int,int>top1 = pq.top();
            pq.pop();
            
            pair<int,int>top2 = pq.top();
            pq.pop();
           
            ans+=(top1.second+'a');
            top1.first--;
            ans+=(top2.second+'a'); 
            top2.first--;
            
            if(top1.first>0){
                pq.push({top1.first,top1.second});
            }
            if(top2.first>0){
                pq.push({top2.first,top2.second});
            } 
        }
        
        if(pq.empty())
            return ans;
      
       if(!pq.empty() && pq.top().first>1)
           return "";
       else if(pq.size()>0){
           ans+=(pq.top().second+'a');
           
       }
        
        
      return ans;
        
    }
};