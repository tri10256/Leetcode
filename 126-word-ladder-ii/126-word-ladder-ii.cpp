class Solution {
public:
    
    vector<vector<string>>paths;
    
    void dfs(string beginWord,string &endWord,unordered_map<string,unordered_set<string>>&adj,vector<string>path){
         path.push_back(beginWord);
        
        if(beginWord == endWord){
            paths.push_back(path);
            return;
        }
        
        for(auto nextnode:adj[beginWord]){
            dfs(nextnode,endWord,adj,path);
        }
        path.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
         unordered_set<string>dict(wordList.begin(),wordList.end());
         unordered_map<string,int>visited;
         unordered_map<string,unordered_set<string>>adj;
        
         queue<string>q;
         q.push(beginWord);
         visited[beginWord] = 0;
         
         while(!q.empty()){
             
             string curr = q.front();
             q.pop();
             
             for(int i = 0;i<curr.size();++i){
                  string temp = curr;
                 for(char c = 'a';c<='z';++c){
                     temp[i] = c;
                     
                     if(temp == curr){
                         continue;
                     }else if(dict.count(temp)){
                         
                         if(!visited.count(temp)){
                             
                             visited[temp] = visited[curr] + 1;
                             q.push(temp);
                             adj[curr].insert(temp);
                             
                         }else{
                             
                             if(visited[temp] == visited[curr] +1)
                             adj[curr].insert(temp);  
                         }
                     }
                 }
             }
         }
         
        vector<string>path;
        dfs(beginWord,endWord,adj,path);
        
        return paths;
    }
};