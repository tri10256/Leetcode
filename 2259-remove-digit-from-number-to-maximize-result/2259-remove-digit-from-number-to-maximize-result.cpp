class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<int>pos;
        for(int i = 0;i<number.size();i++){
            if(number[i] == digit){
                pos.push_back(i);
            }
        }
        
        vector<string>nums;
        for(auto p:pos){
            string  str = "";
            for(int i = 0;i<number.size();i++){
                if(i == p)
                    continue;
                str+=number[i];
            }
            
            nums.push_back(str);
        }
        string res = "";
        for(auto num:nums){
          res = max(res,num);
        }
        
        
       return  res;
    }
};