class Solution {
public:
    char findTheDifference(string s, string t) {
        return accumulate(t.begin(), t.end(), 0, bit_xor<int>()) ^ accumulate(s.begin(), s.end(), 0, bit_xor<int>());
    }
};