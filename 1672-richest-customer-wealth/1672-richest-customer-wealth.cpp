class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int m = accounts.size(); //length of rows
        int n = accounts[0].size(); //length of columns
        int maxWealth = 0;
        for(int i = 0; i < m; i++){
            int wealth = 0;
            for(int j = 0; j < n; j++){
                wealth += accounts[i][j];
            }
                maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};