class Solution {
public:
    int titleToNumber(string columnTitle) {
        
        int count = 0;
        for(int i = 0;i<columnTitle.size();i++){
            count = count*26 +(columnTitle[i]-'A'+1);
        }
        
        return  count;
    }
};