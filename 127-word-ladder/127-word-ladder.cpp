class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        /*took reference from techdose that bfs will applied in the graph for finding
        the shortest path not dfs because becuase a graph have a probability of finding
        exponenital no of paths from source to destination, which bfs will have fixed         shortestpaths
          
        ///compare will give 0for exactmatch                                                           ///1 if temp have more size than curr
          /// -1 if curr have more size than                                                             //temp
          
                                                    
         */
        unordered_set<string>st;
        bool isPresent = false;
        
        for(auto &word:wordList){
           
            if(word == endWord){
                isPresent = true;
            }
            st.insert(word);
        }
        if(!isPresent){
            return 0;
        }
        
        int level = 0;
        queue<string>q;
        q.push(beginWord);
        
        while(!q.empty()){
            level+=1;
            int levelnodes = q.size();
            
            while(levelnodes--){
                
                string curr = q.front();
                q.pop();
                
               
                for(int i = 0;i<curr.size();++i){
                     string temp = curr;
                    for(char c = 'a' ;c<='z';++c){
                          temp[i] = c;
                        
                        if(temp == curr){
                            continue;
                        }else if(temp == endWord){
                            return level+1;
                        }else{
                            
                            if(st.count(temp)){
                                q.push(temp);
                                st.erase(temp);
                            }
                        }
                        
                    }
    
                }
            }
        }
        
        return 0;
    }
};