class Allocator {
public:
    vector<int> v;
    int N;
    Allocator(int n) {
        N = n;
        v.assign(N, -1);
    }
    
    int allocate(int size, int mID) {
        int k = 0;
        for(int i = 0; i < N; ++i) {
            if(v[i] == -1) {
                ++k;
                if(k == size) {
                    fill_n(v.begin() + (i - k + 1), k, mID);
                    return i - k + 1;
                }
            } else {
                k = 0;
            }
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        for(auto& val : v) {
            if(val == mID) {
                val = -1;
                ++cnt;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */