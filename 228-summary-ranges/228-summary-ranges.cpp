class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string>ans;
        string str = "";
        int i = 0;
        int j = 0;
        int n = nums.size();
        if(n == 0)
            return ans;
        
        while(j<n-1){
             
            if(nums[j+1] == nums[j]+1){
                j++;
            }else{
                string str = "";
                if(nums[i] != nums[j]){
                str+=(to_string(nums[i])+"->"+to_string(nums[j]));
                ans.push_back(str);
                str.clear();
                i = j;
                i++;
                j++;
                }else if( nums[i] == nums[j]){
                    str+=to_string(nums[i]);
                    ans.push_back(str);
                    i=j;
                    i++;
                    j++;
                }
            }
        }
        string s = "";
        if(i == j){
            s+=(to_string(nums[i]));
            ans.push_back(s);
        }else{
            s+=(to_string(nums[i]) + "->" + to_string(nums[j]));
            ans.push_back(s);
        }
        
        return ans;
    }
};