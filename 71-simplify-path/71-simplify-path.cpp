class Solution {
public:
    string simplifyPath(string path) {
        string temp = "", res = "";
        stringstream ss(path);
        vector<string>stk;
        
        while(getline(ss,temp,'/')){
            if(temp == "" || temp == ".")
                continue;
            if(temp == ".." && !stk.empty())
                stk.pop_back();
            else if(temp != "..")
                stk.push_back(temp);
        }
        
        for(auto str:stk){
            res+='/'+str;
        }
        
        if(!res.size())
            return "/";
        else
            return res;
    }
};