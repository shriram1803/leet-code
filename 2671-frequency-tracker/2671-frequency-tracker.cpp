class FrequencyTracker {
public:
    unordered_map<int, int> fq, numfq;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        --numfq[fq[number]];
        ++numfq[++fq[number]];
    }
    
    void deleteOne(int number) {
        if(fq[number]) {
            --numfq[fq[number]];
            ++numfq[--fq[number]];
        }
    }
    
    bool hasFrequency(int frequency) {
        return numfq[frequency];
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */