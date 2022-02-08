class Bitset {
public:
    string bs, bs_flip;
    int cnt = 0, flipped = false;
    Bitset(int size) { 
        bs = string(size, '0'); 
        bs_flip = string(size, '1'); 
    }
    void fix(int idx) {
        cnt += bs[idx] == (flipped ? '1' : '0');
        bs[idx] = (flipped ? '0' : '1');
        bs_flip[idx] = (flipped ? '1' : '0');
    }
    void unfix(int idx) {
        cnt -= bs[idx] == (flipped ? '0' : '1');
        bs[idx] = (flipped ? '1' : '0');
        bs_flip[idx] = (flipped ? '0' : '1');
    }
    void flip() { 
        flipped = !flipped; 
        cnt = bs.size() - cnt;
    }
    bool all() { return cnt == bs.size(); }
    bool one() { return cnt != 0; }
    int count() { return cnt; }
    string toString() {
        return flipped ? bs_flip : bs;
    }
};