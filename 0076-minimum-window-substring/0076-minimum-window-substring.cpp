class Solution {
public:
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int minLen = INT_MAX;
        int cnt = 0;
        int sIndex = -1;
        unordered_map<char,int> mpp;
        for(int i = 0; i < t.size(); i++){
            mpp[t[i]]++;
        }
        while(right < s.size()){
            if(mpp[s[right]] > 0){
                cnt++;
            }
            mpp[s[right]]--;
            while(cnt == t.size()){
                if(right-left+1 < minLen){
                    minLen = right-left+1;
                    sIndex = left;
                }
                mpp[s[left]]++;
                if(mpp[s[left]] > 0) cnt--;
                left++;
            }
            right++;
        }
        if(sIndex == -1) return "";
        return (s.substr(sIndex, minLen));
    }
};