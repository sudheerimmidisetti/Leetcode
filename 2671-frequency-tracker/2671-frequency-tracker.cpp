class FrequencyTracker {
public:
    map<int, int> cnt, freq;
    FrequencyTracker() {}

    void add(int number) {
        if (freq[cnt[number]] > 0)
            freq[cnt[number]]--;

        cnt[number]++;
        freq[cnt[number]]++;
    }

    void deleteOne(int number) {
        if (cnt[number] == 0)
            return;

        freq[cnt[number]]--;
        cnt[number]--;

        if (cnt[number] > 0)
            freq[cnt[number]]++;
    }

    bool hasFrequency(int frequency) { return freq[frequency] > 0; }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */