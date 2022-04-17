class Solution {
public:
    string digitSum(string s, int k) {
      
        while(s.size() > k){
            string temp = "";
            int n = s.size();
            int i = 0;
            int  j = 0;
            
            while(j<n){
                
                if((j-i+1) < k)
                    j++;
                else if((j-i+1) == k){
                    string curr = s.substr(i,(j-i+1));
                    
                    int sum = 0;
                    for(int i = 0;i<curr.size();i++){
                        sum+=(curr[i] - '0');
                    }
                    temp+=to_string(sum);
                    i = j+1;
                    j = j+1;
                    
                   
                    
                }
                 
            }
                    string curr = s.substr(i,(j-i));
                    int sum = 0;
                    for(int i = 0;i<curr.size();i++){
                        sum+=(curr[i] - '0');
                    }
                    if(curr.size() > 0)
                    temp+=to_string(sum);
            
            s = temp;
        }
        
        return s;
    }
};