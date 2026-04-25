class Solution {
public:
    int maxDepth(string s) {
        int p = 0;
        int ans = 0;
        for(char x : s){
            if(x == '(') p++;
            if(x == ')') p--;
            ans = max(p, ans);
        }
        return ans;
        
    }
};