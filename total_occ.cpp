class Solution {
public:
    bool areOccurrencesEqual(string s) {

        //use hash map to check frequencies
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        int targetFreq = freq.begin()->second;

        for (auto& pair : freq) {
            if(pair.second != targetFreq)
                return false;
        }
        return true;
        
    }
};