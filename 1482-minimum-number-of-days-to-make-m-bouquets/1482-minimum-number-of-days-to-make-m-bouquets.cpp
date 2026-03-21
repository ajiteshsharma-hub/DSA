class Solution {
public:
    bool isPossible(vector<int>& bloomDay, int day, int m, int k){
        int count = 0;
        int bouquets = 0;
        for(int bloom : bloomDay){
            if(bloom <= day){
                count++;
                if(count == k){
                    bouquets++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
        }
        return bouquets >= m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        long long totalFlowers = 1LL * m * k;
        if(totalFlowers > n) return -1;
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        while(low <= high){
            int mid = (low + high) / 2;
            if(isPossible(bloomDay,mid,m,k)){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};