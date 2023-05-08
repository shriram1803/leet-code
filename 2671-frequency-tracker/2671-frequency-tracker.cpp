class FrequencyTracker {
public:
    int fq[100001] = {}, numfq[100001] = {};
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        numfq[fq[number]] -= 1;
        numfq[++fq[number]] += 1;
    }
    
    void deleteOne(int number) {
        if(fq[number]) {
            numfq[fq[number]] -= 1;
            numfq[--fq[number]] += 1;
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