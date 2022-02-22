class Solution {
public:
    unordered_map<string,string>database;
  
    ////generator function to generate the new tiny urls everytime
    string generate(){
        string key = "";
        srand(time(0));
        for(int i = 0;i<15;i++){
            int r1 = rand()%2;
            if(r1 == 0){
                int r2 = rand()%26;
                key+=(r2+'a');
                
            }else if(r1 == 1){
                int r2 = rand()%26;
                key+=(r2+'A');
            }else {
                int r2 = rand()%9;
                key+=(r2+'0');
            }
        }
        return key;
    }
    
     // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string key = generate();
        
        while(database.count(key)){
            key = generate();
        }
        
        database[key] = longUrl;
        return key;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) { 
        return database[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));