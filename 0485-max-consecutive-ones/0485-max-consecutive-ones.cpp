class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0;
        int ans;
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(nums[i] == 1){
                cnt++;
                ans = max(cnt,ans);
            }
            else{
                cnt = 0;
            }
        }
        return ans;
    }
};