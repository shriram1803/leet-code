class FrequencyTracker {
public:
    int fq[100001] = {0}, numfq[100001] = {0};
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        fq[number] += 1;
        numfq[fq[number]] += 1;
        numfq[fq[number] - 1] -= 1; 
    }
    
    void deleteOne(int number) {
        if(fq[number] > 0) {
            numfq[fq[number]] -= 1;
            numfq[fq[number] - 1] += 1;
            fq[number] -= 1;
        }
    }
    
    bool hasFrequency(int frequency) {
        return numfq[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */