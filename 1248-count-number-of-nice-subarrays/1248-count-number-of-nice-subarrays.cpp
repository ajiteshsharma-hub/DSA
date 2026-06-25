class Solution {
public:
    int countSubarray(vector<int>& nums, int k){
        if(k < 0) return 0;
        int left = 0, right = 0;
        int sum = 0;
        int count = 0;
        while(right < nums.size()){
            sum += (nums[right] % 2);
            while(sum > k){
                sum -= (nums[left] % 2);
                left++;
            }
            count += (right - left + 1);
            right++;
        }
        return count;
    }

public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return (countSubarray(nums, k) - countSubarray(nums, k-1));
    }
};