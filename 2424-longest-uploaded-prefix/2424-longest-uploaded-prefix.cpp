class LUPrefix {
    vector<int> v;
    int lg;
public:
    
    LUPrefix(int n) {
        v.resize(n + 2);
        lg = 0;
    }
    
    void upload(int video) {
        v[video] = 1;
        while(v[lg + 1] == 1) 
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