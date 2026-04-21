class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        if(s.size() != goal.size()) return false;
        for(int i = 0; i < n; i++){
            string rotated = s.substr(i) + s.substr(0,i);
            if(rotated == goal) return true;
        }
        return false;
 
    }
};