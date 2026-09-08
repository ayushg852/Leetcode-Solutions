class FrequencyTracker {
public:
    unordered_map<int,int> freq_map;
    unordered_map<int,int> freq_freq;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        if(freq_map.find(number)!=freq_map.end())
        freq_freq[freq_map[number]]--;
        freq_map[number]++;
        freq_freq[freq_map[number]]++;
    }
    void deleteOne(int number) {
        if(freq_map.find(number)==freq_map.end())
        return;
        freq_freq[freq_map[number]]--;
        freq_map[number]--;
        if(freq_map[number]==0)
        freq_map.erase(number);
        else
        freq_freq[freq_map[number]]++;
    }
    
    bool hasFrequency(int frequency) {
        if(freq_freq.find(frequency)!=freq_freq.end()&&freq_freq[frequency]>0)
        return true;
        return false;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */