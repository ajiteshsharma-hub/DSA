class Solution {
public:
    int maxElement(vector<vector<int>>& mat, int col){
        int n = mat.size();
        int maxValue = INT_MIN;
        int index = -1;
        for(int i = 0; i < n; i++){
            if(mat[i][col] > maxValue){
                maxValue = mat[i][col];
                index = i;
            }
        }
        return index;
    }
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int low = 0 , high = m - 1;
        while(low <= high){
            int mid = (low + high) / 2;
            int row = maxElement(mat, mid);
            int left = INT_MIN;
            int right = INT_MIN;
            if(mid - 1 >= 0){
                left = mat[row][mid-1];
            }

            if(mid + 1 < m){
                right = mat[row][mid+1];
            }

            if(mat[row][mid] > left && mat[row][mid] > right){
                return{row,mid};
            }
            else if(left > mat[row][mid]){
                high = mid - 1; 
            }
            else{
                low = mid + 1;
            }
        }
        return {-1,-1};
    }
};