class LUPrefix {
    vector<int> v;
    int lg, N;
public:
    
    LUPrefix(int n) {
        v.resize(n + 1);
        lg = 0;
        N = n;
    }
    
    void upload(int video) {
        v[video] = 1;
        while(lg < N and v[lg + 1] == 1) 
                lg++;
    }
    
    int longest() {
        return lg;
    }
};

/**
 * Your LUPrefix object will be instantiated and called as such:
 * LUPrefix* obj = new LUPrefix(n);
 * obj->upload(video);
 * int param_2 = obj->longest();
 */