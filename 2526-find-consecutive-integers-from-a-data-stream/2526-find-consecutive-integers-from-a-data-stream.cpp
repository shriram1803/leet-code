class DataStream {
public:
    int K, val_cnt, val;
    DataStream(int value, int k) {
        val = value, K = k, val_cnt = 0;
    }
    
    bool consec(int num) {
        val_cnt = num == val ? val_cnt + 1 : 0;
        if(val_cnt >= K) return true;
        return false;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */