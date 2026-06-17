class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<int> isPrime(n,1);
        isPrime[0] = isPrime[1] = 0;
        int cnt = 0;
        for(int i = 2; i*i < n; i++){
            if(isPrime[i] == 1){
                for(int j = i*i; j < n; j+=i){
                    isPrime[j] = 0;
                }
            }
        }

        for(int i = 2; i < n; i++){
            if(isPrime[i] == 1) cnt++;
        }
        return cnt;
    }
};