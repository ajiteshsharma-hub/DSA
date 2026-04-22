class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int freq[26] = {0};
        for(int i = 0; i < s.length(); i++){
            //Increament frequency for each character in s
            freq[s[i] - 'a']++;
        }
        for(int i = 0; i< t.length(); i++){
            //Decreament frequency for each character in t
            freq[t[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++){
            //Check if frequency is zero or not
            if(freq[i] != 0) return false;
        }
        return true;
    }
};