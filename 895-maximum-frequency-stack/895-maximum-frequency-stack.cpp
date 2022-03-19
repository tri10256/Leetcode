class FreqStack {
public:
    /*
    Already submitted a brute with the use of two stacks
    
    */
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>groups;
    int maxfreq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        maxfreq = max(maxfreq,freq[val]);
        groups[freq[val]].push(val);
    }
    
    int pop() {
        
        int x = groups[maxfreq].top();
        groups[maxfreq].pop();
        freq[x]--;
        
        if(groups[maxfreq].size() == 0)
            maxfreq--;
        
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */