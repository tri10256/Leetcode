class Solution {
public:
    int convertTime(string current, string correct) {
        int curr_hour = stoi(current.substr(0,2));
        int curr_min  = stoi(current.substr(3,2));
        int co_hour = stoi(correct.substr(0,2));
        int co_min  = stoi(correct.substr(3,2));
        
       
        int h_diff = co_hour - curr_hour;
        int min_diff = co_min - curr_min;
        
        int total = h_diff*60 + min_diff;
        vector<int>time{1,5,15,60};
        
        int op = 0;
        for(int i = time.size() -1;i>=0;i--){
            if(total >= time[i] && total >0){
                op+=total/time[i];
                total = total%time[i];
            }
        }
       
        
        
        return op;
    }
};