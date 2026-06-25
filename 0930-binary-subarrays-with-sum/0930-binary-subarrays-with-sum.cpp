class Solution {
public:
    int countSubarray(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int left = 0, right = 0;
        int sum = 0;
        int cnt = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(sum > goal){
                sum -= nums[left];
                left++;
            }
            cnt += (right - left + 1);
            right++;
        }
        return cnt;
    }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return(countSubarray(nums,goal) - countSubarray(nums, goal-1));
    }
};