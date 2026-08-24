class Solution {
public:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
public:
    int maxVowels(string s, int k) {
        int l = 0;
        int vowels = 0;
        int maxVowels = INT_MIN;
        for(int r = 0; r < s.size(); r++){
            if(isVowel(s[r])) vowels++;

            if(r - l + 1 > k){
                if(isVowel(s[l])) vowels--;
                l++;
            }

            if(r - l + 1 == k)maxVowels = max(vowels, maxVowels);

        }

        return maxVowels;
    }
};