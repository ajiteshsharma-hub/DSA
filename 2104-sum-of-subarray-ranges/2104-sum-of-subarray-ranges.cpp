class Solution {
public:
    vector<int> findNSE(vector<int>& nums){
    int n = nums.size();
    vector<int> nse(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] >= nums[i]){
            st.pop();
        }

        if(st.empty()){
            nse[i] = n;
        }
        else{
            nse[i] = st.top();
        }
        st.push(i);
    }
    return nse;
}

vector<int> findPSEE(vector<int>& nums){
    int n = nums.size();
    vector<int> psee(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] > nums[i]){
            st.pop();
        }

        if(st.empty()) psee[i] = -1;
        else psee[i] = st.top();
        st.push(i);
    }

    return psee;
}

vector<int> findNGE(vector<int>& nums){
    int n = nums.size();
    vector<int> nge(n);
    stack<int> st;
    for(int i = n - 1; i >= 0; i--){
        while(!st.empty() && nums[st.top()] <= nums[i]){
            st.pop();
        }

        if(st.empty()){
            nge[i] = n;
        }
        else{
            nge[i] = st.top();
        }
        st.push(i);
    }
    return nge;
}

vector<int> findPGEE(vector<int>& nums){
    int n = nums.size();
    vector<int> pgee(n);
    stack<int> st;
    for(int i = 0; i < n; i++){
        while(!st.empty() && nums[st.top()] < nums[i]){
            st.pop();
        }

        if(st.empty()) pgee[i] = -1;
        else pgee[i] = st.top();
        st.push(i);
    }
    return pgee;
}

long long sumOfSubarrayMinimums(vector<int>& nums){
    vector<int> nse = findNSE(nums);
    vector<int> psee = findPSEE(nums);
    long long total = 0;
    int mod = (int)(1e9 + 7);
    for(int i = 0; i < nums.size(); i++){
        int left = i - psee[i];
        int right = nse[i] - i;
        total = (total + ((long long)left * right * nums[i] * 1LL));
    }

    return total;

}

long long sumOfSubarrayMaximums(vector<int>& nums){
    vector<int> nge = findNGE(nums);
    vector<int> pgee = findPGEE(nums);
    long long total = 0;
    int mod = (int)(1e9 + 7);
    for(int i = 0; i < nums.size(); i++){
        int left = i - pgee[i];
        int right = nge[i] - i;
        total = (total + ((long long)left * right * nums[i] * 1LL));
    }

    return total;

}
    long long subArrayRanges(vector<int>& nums) {
        return sumOfSubarrayMaximums(nums) - sumOfSubarrayMinimums(nums);
    }
};